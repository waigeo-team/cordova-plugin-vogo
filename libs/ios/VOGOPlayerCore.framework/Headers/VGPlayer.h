//
//  VGPlayer.h
//  VOGOPlayerFramework
//
//  Created by VOGO on 11/04/2018.
//  Copyright © 2018 VOGO. All rights reserved.
//
@import UIKit;
@class VGPlayer;
@class VGChannel;
@class InAppPurchaseHistory;
@class VGMarker;

/*!
 * @brief The possible states the Player can be in :
 * Stopped <-> Listening <-> Buffering <-> Rendering
 *
 * @discussion The States are consecutive: to go from Stopped to Rendering,
 * the Player will go through all the intermediary States.
 *
 *  @link #setState
 *  @link #getState
 */
typedef NS_ENUM(NSInteger, State) {
	/*!
	 * @brief The Player is idle. No major resources are allocated (no sockets, video buffers, etc.)
     */
    Stopped,
    /*!
	 * @brief The Player is listening for a VOGO Server configuration on the network.
     */
    Listening,
    /*!
	 * @brief The Player has received a VOGO Server configuration and is buffering the video streams.
     */
    Buffering,
    /*!
	 * @brief The Player is rendering video and audio.
     */
    Rendering,
};

/*!
 * @brief Possible meanings of the seek parameter.
 */
typedef NS_ENUM(NSInteger, SeekMode) {
	/*!
	 * @brief A relative offset in milliseconds. The video position will be moved by the specified offset.
	 */
    OffsetMs,
    /*!
	 * @brief A video position expressed in pipeline referenhtial, in milliseconds.
	 */
    PipelineMs,
    /*!
	 * @brief A video position expressed in epoch UTC milliseconds.
	 */
    EpochMs,
};

/*! 
  * @brief Define the events that the Player can trigger.
  *
  * Each event comes with associated data in a NSDictionnary.
  * Event data keys are defined in VGDefines.h.
  */
typedef NS_ENUM(NSInteger, EventType) {
	/*!
	 * @brief The VOGO Server configuration has changed.
	 *
	 * Event data: the complete current configuration.
	 */
	ConfigChanged,
	/*!
	 * @brief The available Channels streamed by the VOGO Server have changed
	 * (one or several channels have been added, removed, or renamed).
	 * ConfigChanged is always triggered when this event is triggered.
	 *
	 * Event data: undefined (work in progress). Use @link #channels to get the list of channels.
	 */
	ChannelsChanged,
	/*!
	 * @brief The Player @link State has changed.
	 *
	 * Event data:
	 *    - kState: the new state
	 */
	StateChanged,
	/*!
	 * @brief The Player is older than the server and does not includes the latest features.
	 * the server provide. An invitation to update may be shown to the user.
	 *
	 * Event data: none.
	 */
	PlayerTooOldButCompatible,
	/*!
	 * @brief A data file (e.g a sponsor logo image or a PDF document) has been received.
	 *
	 * Event data: the complete current configuration.
	 */
	ContentChanged,
	/*!
	 * @brief Subtitles has been received.
	 * Event data: the received subtitles:
     *   - kSubtitleText
     *   - kSubtitleHorzPos
     *   - kSubtitleVertPos
     *   - kSubtitleColor
     *   - kSubtitleDisplayDelay
     *   - kSubtitleSize
     *   - kSubtitleChannel
	 */
	SubtitlesReceived,
	/*!
	 * @brief Due to a bad Wifi reception, the video rendering stream is hold and waiting for data.
	 * This event is also triggered when the data comes back and the video rendering flows again.
	 *
	 * Event data:
	 *   - kWaiting: if the rendering is waiting or not
	 */
	StreamRenderingChanged,
	/*!
	 * @brief NOT IMPLEMENTED YET.
	 * The player has not received anything for a long time and is not in state @link State#Rendering.
	 * Maybe it is time to completely stop the player.
	 *
	 * Event data: none.
	 */
	TimeoutInBackground,
	/*!
	 * @brief The current channel has changed. This will generally happen once
	 * @link #currentChannel has been called, but might
	 * also happen when the current channel is stopped on server-side.
	 *
	 * Event data: 
	 *   - kChannel: the new current channel.
	 */
	CurrentChannelChanged,
	/*!
	 * @brief The speed has changed. This will generally happen once
	 * @link #speed has been called, but might also happen in other circumstances.
	 *
	 * Event data: 
	 *   - kSpeed: the new current speed.
	 */
	SpeedChanged,
	/*!
	 * @brief The position changed. This will generally happen once
	 * @link #seek has been called, but might also happen in other circumstances.
	 *
	 * Event data: none. Use #liveDesynchronization to get the current position.
	 */
	PositionChanged,
	/*!
     * @brief After a record has been stopped, emitted when the record file is created.
     *
     * Event data: 
     *   - kFilename: the recorded file path.
     */
    RecordFileCreated,
    /*!
	 * @brief NOT IMPLEMENTED YET
	 *
	 * After a preview has been launched, the preview-stop timestamp has been reached.
	 */
    PreviewEnded,
    /*!
     * @brief Internal event. Nothing to do.
     */
    GetAvailableMemory,
    /*!
     * @brief The selected stream needs a platform specific display, or does not need a
     * platform specific display anymore.
     * Platform specific display are needed for DataFile VOGO Server streamsù,
     * which are not standard video streamsù, but are PDF/Image file Channel.
     * See VOGO Console reference documentation for more information.  
     * 
     * Event data: 
     *   - kDisplayAsked: is a platform specific display needed.
     *   - kFilename: the file path of the DataFile
     */
    DisplayAsked,
	/*!
	 * @brief The WiFi connection changed.
	 *
	 * Event data: 
	 *   - kIsConnectedToWifi: the WiFi reachability (YES for reachable, NO for unreachable).
	 */
	WifiConnectionChanged,
};

NS_ASSUME_NONNULL_BEGIN

/*!
 * @brief Methods for notification of the VOGO Player events.
 */
@protocol VGEventListener<NSObject>
//
- (void) player:(VGPlayer*) player eventType:(EventType) eventType values:(nonnull NSDictionary*) values;
//
- (void) player:(VGPlayer*) player receivedError:(NSError*) error;

@end


/*!
 * @brief The Player can bufferize and play videos streams from a VOGO Server.
 *
 * The Player can render one main video and/or various thumbnail videos.
 *
 * @p For its main video, the Player allows to select one video Channel among the various video Channels that the VOGO
 * Server is streaming (see @link #setCurrentChannel(Channel)).
 * @p In addition, the Player allows to create thumbnail videos for each video Channel.
 * @p The Player renders the videos on a SurfaceView (see @link #setSurface(SurfaceView)).
 *
 * @p The Player also allows to pause and control the videos playback rate (see @link #setSpeed(int)).
 *
 * @p The Player bufferizes all the video streams in the device memory (RAM), with one ring-buffer by
 * stream. The size of the ring-buffers depends on the memory available on the device.
 *
 * @p The Player can control the playback position and replay the videos stored in the ring-buffers
 * (see @link #seek(int)).
 * @p When changing the playback position or the playback rate, the main video and the thumbnail videos are affected,
 * so that they always remain synchronized. 
 */

@interface VGPlayer : NSObject


/*!
 * @brief The possible states the player can be in or set.
 * 
 * @discussion The possible states the player can be in:
 * Stopped < - > Listening < - > Buffering < - > Playing
 * 
 * The states are consecutive: to go from Stopped to Playing, the Player will go through all the intermediary States.
 *  @link #setState
 *  @link #getState
 */
@property(assign, nonatomic) State state;

/*!
 @brief The current playback speed.

 @discussion Changes the playback speed, expressed as a percent of normal speed.
 @p   - 100 stands for normal speed.
 @p   - 0 stands for paused.
 @p   - Any other positive value is valid : 50 is 2-times slower, 300 is 3 times faster, etc.
 @p Default: 100.
 
 */
@property(assign, nonatomic) NSUInteger speed;

/*!
 @brief Return YES if the player is waiting for data (mainly because the Wifi reception is bad or lost).
 */
@property(assign, nonatomic, readonly) BOOL isWaiting;

/*!
 * Set a UIView for the Player to draw a video.
 * If channelId is 0, it is the main video.
 * If channelId is the #getId of a Channel, it is a thumbnail video for this Channel.
 *
 * @discussion This UIView MUST have an openGL layer like CAEAGLLayer.
 *
 * @param surface the UIView the Player will draw on.
 *                If nil, the Player will stop drawing on the UIView previously associated with the specified channelId.                   
 *                If the Player was already drawing on another UIView for the specified channelId, 
 *                this function does nothing (call setSurface:nil forChannel:channelId to replace an UIView with another.)
 */
- (void) setSurface:(nullable UIView*)surface forChannel:(NSInteger)channelId;

- (void) setSurface:(nullable UIView*)surface forChannel:(NSInteger)channelId withRenderingId:(NSInteger)renderingId withType:(NSInteger)type withOptions:(NSInteger)options;

- (void) removeSurface:(NSInteger)renderingId;

/*!
 @brief the UIView for the main video.
 
 @discussion Setting this property is an alias to calling setSurface:surface forChannel:0
 */
@property(strong, nonatomic, nullable) UIView* surface;

/*!
 @brief Create a new instance of the VOGO Player without listener.
 
 @return the VOGO Player instance.
 */
- (instancetype) init;

/*!
 @brief Create a new instance of the VOGO Player with the specified listener.
 
 @return the VOGO Player instance.
 */
- (nullable instancetype) initWithListener:(nullable id<VGEventListener>) listener;

/*!
 @brief Register a listener for VGPlayer events.
 
 @return YES if listener was added successfuly ; NO if it was already there.
 */
- (BOOL) addListener:(id<VGEventListener>) listener;

/*!
 @brief Remove a listener for VGPlayer events.
 
  @return YES if listener was removed successfuly NO if it was not there.
 */
- (BOOL) removeListener:(id<VGEventListener>) listener;

/*!
 @brief Return the folder path where resources are stored like event and sponsor images.
 
 @return the resources folder path.
 */
@property(strong, nonatomic, readonly) NSString* resourcesFolder;

/*!
 @brief Return the duration of bufferized video for the current Channel, in milliseconds.
 
 @return the duration of bufferized video for the current Channel, in milliseconds.
 */
- (NSInteger) totalDuration;

/*!
 * @brief Moves the playback position with the specified offset, in millisecond.
 *
 * @p See #SeekMode for the different possible meanings of offset. 
 *
 * @discussion If the resulting playback position is out of the bounds of the video ring-buffer, it will
 * seek to the closest possible position and return YES.
 *
 * @p This function is fail-prone when doing frequently repeated seeks (such as one call for each
 * touch scroll gesture on an UIView). When using mode==OffsetMs, such repeated seeks 
 * should be made with bCumulatedIfFail==YES so that if a seek fails, the failed offset will be 
 * kept in memory and sumed to the next seek, and so on until the seek succeeds.
 *
 * @p When there are a main video and several thumbnails, the decoder load might be heavy when doing
 * repeated seeks, impacting the smoothness of the video. In such cases, it is advisable to 
 * set bForceSyncThumbnails==NO, so that only the main video is seeked. Make one call
 * bForceSyncThumbnails==YES to resynchronize the videos afterwards.
 *
 * @param offset the offset, in millisecond. When using mode==OffsetMs, 
 *               -1 acts as a special value to go back to live.
 */
- (void) seek:(long long) offset withCumulateIfFail:(BOOL) cumulateIfFail withForceResyncThumbnails:(BOOL) forceResync withSeekMode:(SeekMode)seekMode;

/*!
 * @brief Alias to seek:offset withCumulateIfFail:NO withForceResyncThumbnails:YES withSeekMode:OffsetMs.
 */
- (void) seek:(long long) offset;

/*!
 * @brief Alias to seek:offset withCumulateIfFail:cumulateIfFail withForceResyncThumbnails:NO withSeekMode:OffsetMs
 */
- (void) seek:(long long) offset withCumulateIfFail:(BOOL) cumulateIfFail;

/*!
 * @brief Goes back to live position and sets the speed (playback rate) to 100.
 * It is more efficient to call backToLive instead of doing the corresponding
 * separate calls to #seek and #setSpeed.
 */
- (void) backToLive;

/*!
 * @brief Return the time difference between live position and the current playback position in milliseconds.
 *
 * @p This value is always positive. It will generally not be zero, as the player
 * always maintains a safe buffering time from the latest received data.
 *
 * @return the time difference between live position, and the current playback position in milliseconds.
 */
- (NSInteger) liveDesynchronization;

/*!
 * @brief YES if the player is live.
 * @p The Player will be live when a seek is made to its live position (or very near)
 * with a normal playback rate.
 * Thus this is different from liveDesynchronization == 0.
 */
@property(assign, nonatomic, readonly) BOOL isLive;

/*!
 @brief Return the epoch timestamp of the ring-buffer beginning.
 */
- (long long) bufferMinAbsoluteTimestamp;

/*!
 @brief Return the epoch timestamp of the current position
 */
- (long long) currentPosition;

/*!
 @brief Return YES if the current server configuration allows the Player to record the videos to a file.
 */
@property(assign, nonatomic, readonly) BOOL canRecord;

/*!
 @brief Starts recording the current channel at the current position to the specified filePath.
 */
- (void) startRecording:(NSString*)filePath;

/*!
 @brief Stops the current recording at the current position.
 */
- (void) stopRecording;

/*!
 @brief YES if the Player is currently recording.
 */
@property(assign, nonatomic, readonly) BOOL isRecording;

/*!
 * @brief Set the IP to listen for the VOGO Server configuration.
 *
 * @p Default: 234.1.1.99.
 *
 * @param ipAddress the IP to listen for the VOGO Server configuration.
 */
- (void) setListeningIP:(NSString*) ipAddress;
/*!
 * @brief Return the list of available, buffered Channels.
 *
 * @p When the Player is in state #Stopped or #Listening, this list is empty.
 * @p When the Player is in state #Buffering or #Rendering, this list is not empty.
 * @p The list is ordered by ascending Channel#Id.
 *
 * @return the list of Channels
 * 
 * @see EventType#ChannelsChanged
 */
- (NSArray<VGChannel*>*) channels;

/*!
 * @brief Set the current Channel of the main video.
 *
 * @discussion The specified Channel must be among the current available channels (@see #channels).
 *
 * @param newChannel the requested Channel
 */
- (void) setCurrentChannel:(VGChannel*) newChannel;

/*!
 @brief Return the current Channel of the main video.
 
 @return the current Channel, nil if no Channel are available
 @see VGChannel
 */
- (nullable VGChannel*) currentChannel;
 
/*!
@brief Flag a channel as paid when the transaction is successfull
*/
- (void)setPaidChannel:(VGChannel*) channel isPaid: (BOOL) paid;

/*!
@brief Local history of all saved purchases
*/
@property (nonatomic, strong) InAppPurchaseHistory*inAppData;

/*!
@brief Dictionnary with all product identifiers with their tiers ID
*/
@property (nonatomic, retain, nullable)  NSDictionary<NSNumber *, NSString *> * tiersMap;
/*!
@brief Get bundle identifier for an tiers ID
*/
- (NSString* _Nullable ) getIdentifierFor:(NSInteger)tiers;

/*!
 @brief Return dynamic, technical information about the Player.
 
 @return the information. Contains line-breaks.
 */
- (nullable NSString*) debugInfos;

/*!
 @brief Return the current main video source size (width and height).
 
 Note that the Player already scales the current video to fit inside its UIView.
 
 @return the current main video source size.
 */
- (CGSize) videoSize;

/*!
 @brief Return the current player configuration.
 
 @see VGDefines.h for key/value properties.
 
 @return NSDictionary containing current player configuration.
 */
- (nullable NSDictionary* ) configuration;

/*!
 * @brief Associate the Player with a VOGO Events project id, so that the Player can
 * receive video stream from VOGO cloud server, in case there are currently active streams
 * for the specified projectId.
 *
 * Contact VOGO technical team to get a registered project ID.
 */
@property(assign, nonatomic) NSUInteger vogoEventsProject;
/*!
 @brief Sets the path to a valid SSL certificate used for secured requests.
 Default path is AppBundle/ssl/certs/ca-certificates.crt
 */
- (void) setSslCertificatePath:(NSString*)path;

/*!
 @brief Return whether or not the WiFI is reachable.
 
 @return whether or not the WiFI is reachable.
 */
- (BOOL) wifiAvailable;

/*!
 @brief Check if a VOGO Server Configuration is available on the network.
 
 @param timeout in milliseconds
 @param completion the block that will be called once the VOGO Server Configuration has been received,
        or once the timeout expires (whatever happens first). The block is called from the UI main thread.
 
 @return YES if the scan could have been launched.
 */
+ (BOOL) scan:(NSInteger) timeout completion:(void (^)(BOOL hasVOGO))completion;

/*!
@brief Return the last player configuration differential.

@see VGDefines.h for key/value properties.

@return NSDictionary containing player configuration differential.
*/
- (nullable NSDictionary*) configurationDiff;

- (void) setPlayerShareMarkers:(BOOL)share;

/*!
@brief Return the current list of markers

@return NSArray of VGMarker
*/
- (NSArray<VGMarker*>*) getMarkers;

/*!
@brief Go to next or previous marker

@param forward boolean indicating if the player must go to next marker (true) or previous marker (false)
*/
- (void) goToNextMarker:(BOOL)forward
NS_SWIFT_NAME(goToNextMarker(forward:));

/*!
@brief Go to a specific marker identified by its position

@param pos position of the marker expressed in epoch UTC milliseconds.
*/
- (void) goToMarkerByPos:(long long)pos
NS_SWIFT_NAME(goToMarkerByPos(pos:));

@end

NS_ASSUME_NONNULL_END
