
#include <jni.h>


#ifndef _Included_jnitest
#define _Included_jnitest
#ifdef __cplusplus
extern "C" {
#endif
#undef jnitest_FOCUS_TRAVERSABLE_UNKNOWN
#define jnitest_FOCUS_TRAVERSABLE_UNKNOWN 0L
#undef jnitest_FOCUS_TRAVERSABLE_DEFAULT
#define jnitest_FOCUS_TRAVERSABLE_DEFAULT 1L
#undef jnitest_FOCUS_TRAVERSABLE_SET
#define jnitest_FOCUS_TRAVERSABLE_SET 2L
#undef jnitest_TOP_ALIGNMENT
#define jnitest_TOP_ALIGNMENT 0.0f
#undef jnitest_CENTER_ALIGNMENT
#define jnitest_CENTER_ALIGNMENT 0.5f
#undef jnitest_BOTTOM_ALIGNMENT
#define jnitest_BOTTOM_ALIGNMENT 1.0f
#undef jnitest_LEFT_ALIGNMENT
#define jnitest_LEFT_ALIGNMENT 0.0f
#undef jnitest_RIGHT_ALIGNMENT
#define jnitest_RIGHT_ALIGNMENT 1.0f
#undef jnitest_serialVersionUID
#define jnitest_serialVersionUID -7644114512714619750i64
#undef jnitest_serialVersionUID
#define jnitest_serialVersionUID 4613797578919906343i64
#undef jnitest_INCLUDE_SELF
#define jnitest_INCLUDE_SELF 1L
#undef jnitest_SEARCH_HEAVYWEIGHTS
#define jnitest_SEARCH_HEAVYWEIGHTS 1L
#undef jnitest_OPENED
#define jnitest_OPENED 1L
#undef jnitest_serialVersionUID
#define jnitest_serialVersionUID 4497834738069338734i64
#undef jnitest_DEFAULT_CURSOR
#define jnitest_DEFAULT_CURSOR 0L
#undef jnitest_CROSSHAIR_CURSOR
#define jnitest_CROSSHAIR_CURSOR 1L
#undef jnitest_TEXT_CURSOR
#define jnitest_TEXT_CURSOR 2L
#undef jnitest_WAIT_CURSOR
#define jnitest_WAIT_CURSOR 3L
#undef jnitest_SW_RESIZE_CURSOR
#define jnitest_SW_RESIZE_CURSOR 4L
#undef jnitest_SE_RESIZE_CURSOR
#define jnitest_SE_RESIZE_CURSOR 5L
#undef jnitest_NW_RESIZE_CURSOR
#define jnitest_NW_RESIZE_CURSOR 6L
#undef jnitest_NE_RESIZE_CURSOR
#define jnitest_NE_RESIZE_CURSOR 7L
#undef jnitest_N_RESIZE_CURSOR
#define jnitest_N_RESIZE_CURSOR 8L
#undef jnitest_S_RESIZE_CURSOR
#define jnitest_S_RESIZE_CURSOR 9L
#undef jnitest_W_RESIZE_CURSOR
#define jnitest_W_RESIZE_CURSOR 10L
#undef jnitest_E_RESIZE_CURSOR
#define jnitest_E_RESIZE_CURSOR 11L
#undef jnitest_HAND_CURSOR
#define jnitest_HAND_CURSOR 12L
#undef jnitest_MOVE_CURSOR
#define jnitest_MOVE_CURSOR 13L
#undef jnitest_NORMAL
#define jnitest_NORMAL 0L
#undef jnitest_ICONIFIED
#define jnitest_ICONIFIED 1L
#undef jnitest_MAXIMIZED_HORIZ
#define jnitest_MAXIMIZED_HORIZ 2L
#undef jnitest_MAXIMIZED_VERT
#define jnitest_MAXIMIZED_VERT 4L
#undef jnitest_MAXIMIZED_BOTH
#define jnitest_MAXIMIZED_BOTH 6L
#undef jnitest_serialVersionUID
#define jnitest_serialVersionUID 2673458971256075116i64
#undef jnitest_EXIT_ON_CLOSE
#define jnitest_EXIT_ON_CLOSE 3L

JNIEXPORT void JNICALL Java_jnitest_cam
  (JNIEnv *, jobject);


JNIEXPORT jint JNICALL Java_jnitest_direc
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
