/*
 *	$XConsortium: X.h,v 1.66 88/09/06 15:55:56 jim Exp $
 */

/* Definitions for the X window system likely to be used by applications */

#ifndef X_H
#define X_H

/***********************************************************
Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts,
and the Massachusetts Institute of Technology, Cambridge, Massachusetts.

                        All Rights Reserved

Permission to use, copy, modify, and distribute this software and its 
documentation for any purpose and without fee is hereby granted, 
provided that the above copyright notice appear in all copies and that
both that copyright notice and this permission notice appear in 
supporting documentation, and that the names of Digital or MIT not be
used in advertising or publicity pertaining to distribution of the
software without specific, written prior permission.  

DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL
DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR
ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
SOFTWARE.

******************************************************************/
#define X_PROTOCOL	11		/* current protocol version */
#define X_PROTOCOL_REVISION 0		/* current minor version */

#if defined(MAC_OSX_TK)
#   define Cursor XCursor
#   define Region XRegion
#endif

/* Resources */

#ifdef _WIN64
typedef __int64 XID;
#else
typedef unsigned long XID;
#endif

typedef XID Window;
typedef XID Drawable;
typedef XID Font;
typedef XID Pixmap;
typedef XID Cursor;
typedef XID Colormap;
typedef XID GContext;
typedef XID KeySym;

typedef unsigned long Mask;

typedef unsigned long Atom;

typedef unsigned long VisualID;

typedef unsigned long Time;

typedef unsigned long KeyCode;	/* In order to use IME, the Macintosh needs
				 * to pack 3 bytes into the keyCode field in
				 * the XEvent.  In the real X.h, a KeyCode is
				 * defined as a short, which wouldn't be big
				 * enough. */

/*****************************************************************
 * RESERVED RESOURCE AND CONSTANT DEFINITIONS
 *****************************************************************/

#define None                 0L	/* universal null resource or null atom */

#define ParentRelative       1L	/* background pixmap in CreateWindow
				    and ChangeWindowAttributes */

#define CopyFromParent       0L	/* border pixmap in CreateWindow
				       and ChangeWindowAttributes
				   special VisualID and special window
				       class passed to CreateWindow */

#define PointerWindow        0L	/* destination window in SendEvent */
#define InputFocus           1L	/* destination window in SendEvent */

#define PointerRoot          1L	/* focus window in SetInputFocus */

#define AnyPropertyType      0L	/* special Atom, passed to GetProperty */

#define AnyKey		     0L	/* special Key Code, passed to GrabKey */

#define AnyButton            0L	/* special Button Code, passed to GrabButton */

#define AllTemporary         0L	/* special Resource ID passed to KillClient */

#define CurrentTime          0L	/* special Time */

#define NoSymbol	     0L	/* special KeySym */

/***************************************************************** 
 * EVENT DEFINITIONS 
 *****************************************************************/

/* Input Event Masks. Used as event-mask window attribute and as arguments
   to Grab requests.  Not to be confused with event names.  */

#define NoEventMask			0L
#define KeyPressMask			(1L<<0)  
#define KeyReleaseMask			(1L<<1)  
#define ButtonPressMask			(1L<<2)  
#define ButtonReleaseMask		(1L<<3)  
#define EnterWindowMask			(1L<<4)  
#define LeaveWindowMask			(1L<<5)  
#define PointerMotionMask		(1L<<6)  
#define PointerMotionHintMask		(1L<<7)  
#define Button1MotionMask		(1L<<8)  
#define Button2MotionMask		(1L<<9)  
#define Button3MotionMask		(1L<<10) 
#define Button4MotionMask		(1L<<11) 
#define Button5MotionMask		(1L<<12) 
#define ButtonMotionMask		(1L<<13) 
#define KeymapStateMask			(1L<<14)
#define ExposureMask			(1L<<15) 
#define VisibilityChangeMask		(1L<<16) 
#define StructureNotifyMask		(1L<<17) 
#define ResizeRedirectMask		(1L<<18) 
#define SubstructureNotifyMask		(1L<<19) 
#define SubstructureRedirectMask	(1L<<20) 
#define FocusChangeMask			(1L<<21) 
#define PropertyChangeMask		(1L<<22) 
#define ColormapChangeMask		(1L<<23) 
#define OwnerGrabButtonMask		(1L<<24) 

/* Event names.  Used in "type" field in XEvent structures.  Not to be
confused with event masks above.  They start from 2 because 0 and 1
are reserved in the protocol for errors and replies. */

#define KeyPress		2
#define KeyRelease		3
#define ButtonPress		4
#define ButtonRelease		5
#define MotionNotify		6
#define EnterNotify		7
#define LeaveNotify		8
#define FocusIn			9
#define FocusOut		10
#define KeymapNotify		11
#define Expose			12
#define GraphicsExpose		13
#define NoExpose		14
#define VisibilityNotify	15
#define CreateNotify		16
#define DestroyNotify		17
#define UnmapNotify		18
#define MapNotify		19
#define MapRequest		20
#define ReparentNotify		21
#define ConfigureNotify		22
#define ConfigureRequest	23
#define GravityNotify		24
#define ResizeRequest		25
#define CirculateNotify		26
#define CirculateRequest	27
#define PropertyNotify		28
#define SelectionClear		29
#define SelectionRequest	30
#define SelectionNotify		31
#define ColormapNotify		32
#define ClientMessage		33
#define MappingNotify		34
#define LASTEvent		35	/* must be bigger than any event # */


/* Key masks. Used as modifiers to GrabButton and GrabKey, results of QueryPointer,
   state in various key-, mouse-, and button-related events. */

#define ShiftMask		(1<<0)
#define LockMask		(1<<1)
#define ControlMask		(1<<2)
#define Mod1Mask		(1<<3)
#define Mod2Mask		(1<<4)
#define Mod3Mask		(1<<5)
#define Mod4Mask		(1<<6)
#define Mod5Mask		(1<<7)

/* modifier names.  Used to build a SetModifierMapping request or
   to read a GetModifierMapping request.  These correspond to the
   masks defined above. */
#define ShiftMapIndex		0
#define LockMapIndex		1
#define ControlMapIndex		2
#define Mod1MapIndex		3
#define Mod2MapIndex		4
#define Mod3MapIndex		5
#define Mod4MapIndex		6
#define Mod5MapIndex		7


/* button masks.  Used in same manner as Key masks above. Not to be confused
   with button names below. */

#define Button1Mask		(1<<8)
#define Button2Mask		(1<<9)
#define Button3Mask		(1<<10)
#define Button4Mask		(1<<11)
#define Button5Mask		(1<<12)

#define AnyModifier		(1<<15)  /* used in GrabButton, GrabKey */


/* button names. Used as arguments to GrabButton and as detail in ButtonPress
   and ButtonRelease events.  Not to be confused with button masks above.
   Note that 0 is already defined above as "AnyButton".  */

#define Button1			1
#define Button2			2
#define Button3			3
#define Button4			4
#define Button5			5

/* Notify modes */

#define NotifyNormal		0
#define NotifyGrab		1
#define NotifyUngrab		2
#define NotifyWhileGrabbed	3

#define NotifyHint		1	/* for MotionNotify events */
		       
/* Notify detail */

#define NotifyAncestor		0
#define NotifyVirtual		1
#define NotifyInferior		2
#define NotifyNonlinear		3
#define NotifyNonlinearVirtual	4
#define NotifyPointer		5
#define NotifyPointerRoot	6
#define NotifyDetailNone	7

/* Visibility notify */

#define VisibilityUnobscured		0
#define VisibilityPartiallyObscured	1
#define VisibilityFullyObscured		2

/* Circulation request */

#define PlaceOnTop		0
#define PlaceOnBottom		1

/* protocol families */

#define FamilyInternet		0
#define FamilyDECnet		1
#define FamilyChaos		2

/* Property notification */

#define PropertyNewValue	0
#define PropertyDelete		1

/* Color Map notification */

#define ColormapUninstalled	0
#define ColormapInstalled	1

/* GrabPointer, GrabButton, GrabKeyboard, GrabKey Modes */

#define GrabModeSync		0
#define GrabModeAsync		1

/* GrabPointer, GrabKeyboard reply status */

#define GrabSuccess		0
#define AlreadyGrabbed		1
#define GrabInvalidTime		2
#define GrabNotViewable		3
#define GrabFrozen		4

/* AllowEvents modes */

#define AsyncPointer		0
#define SyncPointer		1
#define ReplayPointer		2
#define AsyncKeyboard		3
#define SyncKeyboard		4
#define ReplayKeyboard		5
#define AsyncBoth		6
#define SyncBoth		7

/* Used in SetInputFocus, GetInputFocus */

#define RevertToNone		(int)None
#define RevertToPointerRoot	(int)PointerRoot
#define RevertToParent		2

/*****************************************************************
 * ERROR CODES 
 *****************************************************************/

#define Success		   0	/* everything's okay */
#define BadRequest	   1	/* bad request code */
#define BadValue	   2	/* int parameter out of range */
#define BadWindow	   3	/* parameter not a Window */
#define BadPixmap	   4	/* parameter not a Pixmap */
#define BadAtom		   5	/* parameter not an Atom */
#define BadCursor	   6	/* parameter not a Cursor */
#define BadFont		   7	/* parameter not a Font */
#define BadMatch	   8	/* parameter mismatch */
#define BadDrawable	   9	/* parameter not a Pixmap or Window */
#define BadAccess	  10	/* depending on context:
				 - key/button already grabbed
				 - attempt to free an illegal 
				   cmap entry 
				- attempt to store into a read-only 
				   color map entry.
 				- attempt to modify the access control
				   list from other than the local host.
				*/
#define BadAlloc	  11	/* insufficient resources */
#define BadColor	  12	/* no such colormap */
#define BadGC		  13	/* parameter not a GC */
#define BadIDChoice	  14	/* choice not in range or already used */
#define BadName		  15	/* font or color name doesn't exist */
#define BadLength	  16	/* Request length incorrect */
#define BadImplementation 17	/* server is defective */

#define FirstExtensionError	128
#define LastExtensionError	255

/*****************************************************************
 * WINDOW DEFINITIONS 
 *****************************************************************/

/* Window classes used by CreateWindow */
/* Note that CopyFromParent is already defined as 0 above */

#define InputOutput		1
#define InputOnly		2

/* Window attributes for CreateWindow and ChangeWindowAttributes */

#define CWBackPixmap		(1L<<0)
#define CWBackPixel		(1L<<1)
#define CWBorderPixmap		(1L<<2)
#define CWBorderPixel           (1L<<3)
#define CWBitGravity		(1L<<4)
#define CWWinGravity		(1L<<5)
#define CWBackingStore          (1L<<6)
#define CWBackingPlanes	        (1L<<7)
#define CWBackingPixel	        (1L<<8)
#define CWOverrideRedirect	(1L<<9)
#define CWSaveUnder		(1L<<10)
#define CWEventMask		(1L<<11)
#define CWDontPropagate	        (1L<<12)
#define CWColormap		(1L<<13)
#define CWCursor	        (1L<<14)

/* ConfigureWindow structure */

#define CWX			(1<<0)
#define CWY			(1<<1)
#define CWWidth			(1<<2)
#define CWHeight		(1<<3)
#define CWBorderWidth		(1<<4)
#define CWSibling		(1<<5)
#define CWStackMode		(1<<6)


/* Bit Gravity */

#define ForgetGravity		0
#define NorthWestGravity	1
#define NorthGravity		2
#define NorthEastGravity	3
#define WestGravity		4
#define CenterGravity		5
#define EastGravity		6
#define SouthWestGravity	7
#define SouthGravity		8
#define SouthEastGravity	9
#define StaticGravity		10

/* Window gravity + bit gravity above */

#define UnmapGravity		0

/* Used in CreateWindow for backing-store hint */

#define NotUseful               0
#define WhenMapped              1
#define Always                  2

/* Used in GetWindowAttributes reply */

#define IsUnmapped		0
#define IsUnviewable		1
#define IsViewable		2

/* Used in ChangeSaveSet */

#define SetModeInsert           0
#define SetModeDelete           1

/* Used in ChangeCloseDownMode */

#define DestroyAll              0
#define RetainPermanent         1
#define RetainTemporary         2

/* Window stacking method (in configureWindow) */

#define Above                   0
#define Below                   1
#define TopIf                   2
#define BottomIf                3
#define Opposite                4

/* Circulation direction */

#define RaiseLowest             0
#define LowerHighest            1

/* Property modes */

#define PropModeReplace         0
#define PropModePrepend         1
#define PropModeAppend          2

/*****************************************************************
 * GRAPHICS DEFINITIONS
 *****************************************************************/

/* graphics functions, as in GC.alu */

#define	GXclear			0x0		/* 0 */
#define GXand			0x1		/* src AND dst */
#define GXandReverse		0x2		/* src AND NOT dst */
#define GXcopy			0x3		/* src */
#define GXandInverted		0x4		/* NOT src AND dst */
#define	GXnoop			0x5		/* dst */
#define GXxor			0x6		/* src XOR dst */
#define GXor			0x7		/* src OR dst */
#define GXnor			0x8		/* NOT src AND NOT dst */
#define GXequiv			0x9		/* NOT src XOR dst */
#define GXinvert		0xa		/* NOT dst */
#define GXorReverse		0xb		/* src OR NOT dst */
#define GXcopyInverted		0xc		/* NOT src */
#define GXorInverted		0xd		/* NOT src OR dst */
#define GXnand			0xe		/* NOT src OR NOT dst */
#define GXset			0xf		/* 1 */

/* LineStyle */

#define LineSolid		0
#define LineOnOffDash		1
#define LineDoubleDash		2

/* capStyle */

#define CapNotLast		0
#define CapButt			1
#define CapRound		2
#define CapProjecting		3

/* joinStyle */

#define JoinMiter		0
#define JoinRound		1
#define JoinBevel		2

/* fillStyle */

#define FillSolid		0
#define FillTiled		1
#define FillStippled		2
#define FillOpaqueStippled	3

/* fillRule */

#define EvenOddRule		0
#define WindingRule		1

/* subwindow mode */

#define ClipByChildren		0
#define IncludeInferiors	1

/* SetClipRectangles ordering */

#define Unsorted		0
#define YSorted			1
#define YXSorted		2
#define YXBanded		3

/* CoordinateMode for drawing routines */

#define CoordModeOrigin		0	/* relative to the origin */
#define CoordModePrevious       1	/* relative to previous point */

/* Polygon shapes */

#define Complex			0	/* paths may intersect */
#define Nonconvex		1	/* no paths intersect, but not convex */
#define Convex			2	/* wholly convex */

/* Arc modes for PolyFillArc */

#define ArcChord		0	/* join endpoints of arc */
#define ArcPieSlice		1	/* join endpoints to center of arc */

/* GC components: masks used in CreateGC, CopyGC, ChangeGC, OR'ed into
   GC.stateChanges */

#define GCFunction              (1L<<0)
#define GCPlaneMask             (1L<<1)
#define GCForeground            (1L<<2)
#define GCBackground            (1L<<3)
#define GCLineWidth             (1L<<4)
#define GCLineStyle             (1L<<5)
#define GCCapStyle              (1L<<6)
#define GCJoinStyle		(1L<<7)
#define GCFillStyle		(1L<<8)
#define GCFillRule		(1L<<9) 
#define GCTile			(1L<<10)
#define GCStipple		(1L<<11)
#define GCTileStipXOrigin	(1L<<12)
#define GCTileStipYOrigin	(1L<<13)
#define GCFont 			(1L<<14)
#define GCSubwindowMode		(1L<<15)
#define GCGraphicsExposures     (1L<<16)
#define GCClipXOrigin		(1L<<17)
#define GCClipYOrigin		(1L<<18)
#define GCClipMask		(1L<<19)
#define GCDashOffset		(1L<<20)
#define GCDashList		(1L<<21)
#define GCArcMode		(1L<<22)

#define GCLastBit		22
/*****************************************************************
 * FONTS 
 *****************************************************************/

/* used in QueryFont -- draw direction */

#define FontLeftToRight		0
#define FontRightToLeft		1

#define FontChange		255

/*****************************************************************
 *  IMAGING 
 *****************************************************************/

/* ImageFormat -- PutImage, GetImage */

#define XYBitmap		0	/* depth 1, XYFormat */
#define XYPixmap		1	/* depth == drawable depth */
#define ZPixmap			2	/* depth == drawable depth */

/*****************************************************************
 *  COLOR MAP STUFF 
 *****************************************************************/

/* For CreateColormap */

#define AllocNone		0	/* create map with no entries */
#define AllocAll		1	/* allocate entire map writeable */


/* Flags used in StoreNamedColor, StoreColors */

#define DoRed			(1<<0)
#define DoGreen			(1<<1)
#define DoBlue			(1<<2)

/*****************************************************************
 * CURSOR STUFF
 *****************************************************************/

/* QueryBestSize Class */

#define CursorShape		0	/* largest size that can be displayed */
#define TileShape		1	/* size tiled fastest */
#define StippleShape		2	/* size stippled fastest */

/***************************************************************** 
 * KEYBOARD/POINTER STUFF
 *****************************************************************/

#define AutoRepeatModeOff	0
#define AutoRepeatModeOn	1
#define AutoRepeatModeDefault	2

#define LedModeOff		0
#define LedModeOn		1

/* masks for ChangeKeyboardControl */

#define KBKeyClickPercent	(1L<<0)
#define KBBellPercent		(1L<<1)
#define KBBellPitch		(1L<<2)
#define KBBellDuration		(1L<<3)
#define KBLed			(1L<<4)
#define KBLedMode		(1L<<5)
#define KBKey			(1L<<6)
#define KBAutoRepeatMode	(1L<<7)

#define MappingSuccess     	0
#define MappingBusy        	1
#define MappingFailed		2

#define MappingModifier		0
#define MappingKeyboard		1
#define MappingPointer		2

/*****************************************************************
 * SCREEN SAVER STUFF 
 *****************************************************************/

#define DontPreferBlanking	0
#define PreferBlanking		1
#define DefaultBlanking		2

#define DisableScreenSaver	0
#define DisableScreenInterval	0

#define DontAllowExposures	0
#define AllowExposures		1
#define DefaultExposures	2

/* for ForceScreenSaver */

#define ScreenSaverReset 0
#define ScreenSaverActive 1

/*****************************************************************
 * HOSTS AND CONNECTIONS
 *****************************************************************/

/* for ChangeHosts */

#define HostInsert		0
#define HostDelete		1

/* for ChangeAccessControl */

#define EnableAccess		1      
#define DisableAccess		0

/* Display classes  used in opening the connection 
 * Note that the statically allocated ones are even numbered and the
 * dynamically changeable ones are odd numbered */

#define StaticGray		0
#define GrayScale		1
#define StaticColor		2
#define PseudoColor		3
#define TrueColor		4
#define DirectColor		5


/* Byte order  used in imageByteOrder and bitmapBitOrder */

#define LSBFirst		0
#define MSBFirst		1

#if defined(MAC_OSX_TK)
#   undef Cursor
#   undef Region
#endif

#endif /* X_H */
/************************************************************

Copyright 1989, 1998  The Open Group

Permission to use, copy, modify, distribute, and sell this software and its
documentation for any purpose is hereby granted without fee, provided that
the above copyright notice appear in all copies and that both that
copyright notice and this permission notice appear in supporting
documentation.

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of The Open Group shall not be
used in advertising or otherwise to promote the sale, use or other dealings
in this Software without prior written authorization from The Open Group.

********************************************************/

/* THIS IS NOT AN X CONSORTIUM STANDARD OR AN X PROJECT TEAM SPECIFICATION */

#ifndef _XSHM_H_
#define _XSHM_H_

#include <Xfuncproto.h>
#include <shm.h>

#ifndef _XSHM_SERVER_
typedef unsigned long ShmSeg;

typedef struct {
    int	type;		    /* of event */
    unsigned long serial;   /* # of last request processed by server */
    Bool send_event;	    /* true if this came frome a SendEvent request */
    Display *display;	    /* Display the event was read from */
    Drawable drawable;	    /* drawable of request */
    int major_code;	    /* ShmReqCode */
    int minor_code;	    /* X_ShmPutImage */
    ShmSeg shmseg;	    /* the ShmSeg used in the request */
    unsigned long offset;   /* the offset into ShmSeg used in the request */
} XShmCompletionEvent;

typedef struct {
    ShmSeg shmseg;	/* resource id */
    int shmid;		/* kernel id */
    char *shmaddr;	/* address in client */
    Bool readOnly;	/* how the server should attach it */
} XShmSegmentInfo;

_XFUNCPROTOBEGIN

Bool XShmQueryExtension(
    Display*		/* dpy */
);

int XShmGetEventBase(
    Display* 		/* dpy */
);

Bool XShmQueryVersion(
    Display*		/* dpy */,
    int*		/* majorVersion */,
    int*		/* minorVersion */,
    Bool*		/* sharedPixmaps */
);

int XShmPixmapFormat(
    Display*		/* dpy */
);

Status XShmAttach(
    Display*		/* dpy */,
    XShmSegmentInfo*	/* shminfo */
);

Status XShmDetach(
    Display*		/* dpy */,
    XShmSegmentInfo*	/* shminfo */
);

Status XShmPutImage(
    Display*		/* dpy */,
    Drawable		/* d */,
    GC			/* gc */,
    XImage*		/* image */,
    int			/* src_x */,
    int			/* src_y */,
    int			/* dst_x */,
    int			/* dst_y */,
    unsigned int	/* src_width */,
    unsigned int	/* src_height */,
    Bool		/* send_event */
);

Status XShmGetImage(
    Display*		/* dpy */,
    Drawable		/* d */,
    XImage*		/* image */,
    int			/* x */,
    int			/* y */,
    unsigned long	/* plane_mask */
);

XImage *XShmCreateImage(
    Display*		/* dpy */,
    Visual*		/* visual */,
    unsigned int	/* depth */,
    int			/* format */,
    char*		/* data */,
    XShmSegmentInfo*	/* shminfo */,
    unsigned int	/* width */,
    unsigned int	/* height */
);

Pixmap XShmCreatePixmap(
    Display*		/* dpy */,
    Drawable		/* d */,
    char*		/* data */,
    XShmSegmentInfo*	/* shminfo */,
    unsigned int	/* width */,
    unsigned int	/* height */,
    unsigned int	/* depth */
);

_XFUNCPROTOEND
#endif /* _XSHM_SERVER_ */

#endif
#ifndef XATOM_H
#define XATOM_H 1

/* THIS IS A GENERATED FILE
 *
 * Do not change!  Changing this file implies a protocol change!
 */

#define XA_PRIMARY ((Atom) 1)
#define XA_SECONDARY ((Atom) 2)
#define XA_ARC ((Atom) 3)
#define XA_ATOM ((Atom) 4)
#define XA_BITMAP ((Atom) 5)
#define XA_CARDINAL ((Atom) 6)
#define XA_COLORMAP ((Atom) 7)
#define XA_CURSOR ((Atom) 8)
#define XA_CUT_BUFFER0 ((Atom) 9)
#define XA_CUT_BUFFER1 ((Atom) 10)
#define XA_CUT_BUFFER2 ((Atom) 11)
#define XA_CUT_BUFFER3 ((Atom) 12)
#define XA_CUT_BUFFER4 ((Atom) 13)
#define XA_CUT_BUFFER5 ((Atom) 14)
#define XA_CUT_BUFFER6 ((Atom) 15)
#define XA_CUT_BUFFER7 ((Atom) 16)
#define XA_DRAWABLE ((Atom) 17)
#define XA_FONT ((Atom) 18)
#define XA_INTEGER ((Atom) 19)
#define XA_PIXMAP ((Atom) 20)
#define XA_POINT ((Atom) 21)
#define XA_RECTANGLE ((Atom) 22)
#define XA_RESOURCE_MANAGER ((Atom) 23)
#define XA_RGB_COLOR_MAP ((Atom) 24)
#define XA_RGB_BEST_MAP ((Atom) 25)
#define XA_RGB_BLUE_MAP ((Atom) 26)
#define XA_RGB_DEFAULT_MAP ((Atom) 27)
#define XA_RGB_GRAY_MAP ((Atom) 28)
#define XA_RGB_GREEN_MAP ((Atom) 29)
#define XA_RGB_RED_MAP ((Atom) 30)
#define XA_STRING ((Atom) 31)
#define XA_VISUALID ((Atom) 32)
#define XA_WINDOW ((Atom) 33)
#define XA_WM_COMMAND ((Atom) 34)
#define XA_WM_HINTS ((Atom) 35)
#define XA_WM_CLIENT_MACHINE ((Atom) 36)
#define XA_WM_ICON_NAME ((Atom) 37)
#define XA_WM_ICON_SIZE ((Atom) 38)
#define XA_WM_NAME ((Atom) 39)
#define XA_WM_NORMAL_HINTS ((Atom) 40)
#define XA_WM_SIZE_HINTS ((Atom) 41)
#define XA_WM_ZOOM_HINTS ((Atom) 42)
#define XA_MIN_SPACE ((Atom) 43)
#define XA_NORM_SPACE ((Atom) 44)
#define XA_MAX_SPACE ((Atom) 45)
#define XA_END_SPACE ((Atom) 46)
#define XA_SUPERSCRIPT_X ((Atom) 47)
#define XA_SUPERSCRIPT_Y ((Atom) 48)
#define XA_SUBSCRIPT_X ((Atom) 49)
#define XA_SUBSCRIPT_Y ((Atom) 50)
#define XA_UNDERLINE_POSITION ((Atom) 51)
#define XA_UNDERLINE_THICKNESS ((Atom) 52)
#define XA_STRIKEOUT_ASCENT ((Atom) 53)
#define XA_STRIKEOUT_DESCENT ((Atom) 54)
#define XA_ITALIC_ANGLE ((Atom) 55)
#define XA_X_HEIGHT ((Atom) 56)
#define XA_QUAD_WIDTH ((Atom) 57)
#define XA_WEIGHT ((Atom) 58)
#define XA_POINT_SIZE ((Atom) 59)
#define XA_RESOLUTION ((Atom) 60)
#define XA_COPYRIGHT ((Atom) 61)
#define XA_NOTICE ((Atom) 62)
#define XA_FONT_NAME ((Atom) 63)
#define XA_FAMILY_NAME ((Atom) 64)
#define XA_FULL_NAME ((Atom) 65)
#define XA_CAP_HEIGHT ((Atom) 66)
#define XA_WM_CLASS ((Atom) 67)
#define XA_WM_TRANSIENT_FOR ((Atom) 68)

#define XA_LAST_PREDEFINED ((Atom) 68)
#endif /* XATOM_H */
/* $XConsortium: Xfuncproto.h,v 1.7 91/05/13 20:49:21 rws Exp $ */
/* 
 * Copyright 1989, 1991 by the Massachusetts Institute of Technology
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose and without fee is hereby granted, provided 
 * that the above copyright notice appear in all copies and that both that 
 * copyright notice and this permission notice appear in supporting 
 * documentation, and that the name of M.I.T. not be used in advertising
 * or publicity pertaining to distribution of the software without specific, 
 * written prior permission. M.I.T. makes no representations about the 
 * suitability of this software for any purpose.  It is provided "as is"
 * without express or implied warranty.
 *
 */

/* Definitions to make function prototypes manageable */

#ifndef _XFUNCPROTO_H_
#define _XFUNCPROTO_H_

#ifndef NeedFunctionPrototypes
#define NeedFunctionPrototypes 1
#endif /* NeedFunctionPrototypes */

#ifndef NeedVarargsPrototypes
#define NeedVarargsPrototypes 0
#endif /* NeedVarargsPrototypes */

#if NeedFunctionPrototypes

#ifndef NeedNestedPrototypes
#define NeedNestedPrototypes 1
#endif /* NeedNestedPrototypes */

#ifndef _Xconst
#define _Xconst const
#endif /* _Xconst */

#ifndef NeedWidePrototypes
#ifdef NARROWPROTO
#define NeedWidePrototypes 0
#else
#define NeedWidePrototypes 1		/* default to make interropt. easier */
#endif
#endif /* NeedWidePrototypes */

#endif /* NeedFunctionPrototypes */

#ifdef __cplusplus
#define _XFUNCPROTOBEGIN extern "C" {
#define _XFUNCPROTOEND }
#endif

#ifndef _XFUNCPROTOBEGIN
#define _XFUNCPROTOBEGIN
#define _XFUNCPROTOEND
#endif /* _XFUNCPROTOBEGIN */

#endif /* _XFUNCPROTO_H_ */
/* $XConsortium: Xlib.h,v 11.221 93/07/02 14:13:28 gildea Exp $ */
/* 
 * Copyright 1985, 1986, 1987, 1991 by the Massachusetts Institute of Technology
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose and without fee is hereby granted, provided 
 * that the above copyright notice appear in all copies and that both that 
 * copyright notice and this permission notice appear in supporting 
 * documentation, and that the name of M.I.T. not be used in advertising
 * or publicity pertaining to distribution of the software without specific, 
 * written prior permission. M.I.T. makes no representations about the 
 * suitability of this software for any purpose.  It is provided "as is"
 * without express or implied warranty.
 *
 * X Window System is a Trademark of MIT.
 *
 */


/*
 *	Xlib.h - Header definition and support file for the C subroutine
 *	interface library (Xlib) to the X Window System Protocol (V11).
 *	Structures and symbols starting with "_" are private to the library.
 */
#ifndef _XLIB_H_
#define _XLIB_H_

#define XlibSpecificationRelease 5

#if !defined(MAC_OSX_TK)
#   include <X.h>
#endif
#ifdef MAC_OSX_TK
#   include <X.h>
#   define Cursor XCursor
#   define Region XRegion
#endif

/* applications should not depend on these two headers being included! */
#include <Xfuncproto.h>

#ifndef X_WCHAR
#ifdef X_NOT_STDC_ENV
#define X_WCHAR
#endif
#endif

#ifndef X_WCHAR
#include <stddef.h>
#else
/* replace this with #include or typedef appropriate for your system */
typedef unsigned long wchar_t;
#endif

typedef char *XPointer;

#define Bool int
#if defined(MAC_OSX_TK)
/* Use define rather than typedef, since may need to undefine this later */
#define Status int
#else
typedef int Status;
#endif
#define True 1
#define False 0

#define QueuedAlready 0
#define QueuedAfterReading 1
#define QueuedAfterFlush 2

#define ConnectionNumber(dpy) 	((dpy)->fd)
#define RootWindow(dpy, scr) 	(((dpy)->screens[(scr)]).root)
#define DefaultScreen(dpy) 	((dpy)->default_screen)
#define DefaultRootWindow(dpy) 	(((dpy)->screens[(dpy)->default_screen]).root)
#define DefaultVisual(dpy, scr) (((dpy)->screens[(scr)]).root_visual)
#define DefaultGC(dpy, scr) 	(((dpy)->screens[(scr)]).default_gc)
#define BlackPixel(dpy, scr) 	(((dpy)->screens[(scr)]).black_pixel)
#define WhitePixel(dpy, scr) 	(((dpy)->screens[(scr)]).white_pixel)
#define AllPlanes 		((unsigned long)~0L)
#define QLength(dpy) 		((dpy)->qlen)
#define DisplayWidth(dpy, scr) 	(((dpy)->screens[(scr)]).width)
#define DisplayHeight(dpy, scr) (((dpy)->screens[(scr)]).height)
#define DisplayWidthMM(dpy, scr)(((dpy)->screens[(scr)]).mwidth)
#define DisplayHeightMM(dpy, scr)(((dpy)->screens[(scr)]).mheight)
#define DisplayPlanes(dpy, scr) (((dpy)->screens[(scr)]).root_depth)
#define DisplayCells(dpy, scr) 	(DefaultVisual((dpy), (scr))->map_entries)
#define ScreenCount(dpy) 	((dpy)->nscreens)
#define ServerVendor(dpy) 	((dpy)->vendor)
#define ProtocolVersion(dpy) 	((dpy)->proto_major_version)
#define ProtocolRevision(dpy) 	((dpy)->proto_minor_version)
#define VendorRelease(dpy) 	((dpy)->release)
#define DisplayString(dpy) 	((dpy)->display_name)
#define DefaultDepth(dpy, scr) 	(((dpy)->screens[(scr)]).root_depth)
#define DefaultColormap(dpy, scr)(((dpy)->screens[(scr)]).cmap)
#define BitmapUnit(dpy) 	((dpy)->bitmap_unit)
#define BitmapBitOrder(dpy) 	((dpy)->bitmap_bit_order)
#define BitmapPad(dpy) 		((dpy)->bitmap_pad)
#define ImageByteOrder(dpy) 	((dpy)->byte_order)
#define NextRequest(dpy)	((dpy)->request + 1)
#define LastKnownRequestProcessed(dpy)	((dpy)->request)

/* macros for screen oriented applications (toolkit) */
#define ScreenOfDisplay(dpy, scr)(&((dpy)->screens[(scr)]))
#define DefaultScreenOfDisplay(dpy) (&((dpy)->screens[(dpy)->default_screen]))
#define DisplayOfScreen(s)	((s)->display)
#define RootWindowOfScreen(s)	((s)->root)
#define BlackPixelOfScreen(s)	((s)->black_pixel)
#define WhitePixelOfScreen(s)	((s)->white_pixel)
#define DefaultColormapOfScreen(s)((s)->cmap)
#define DefaultDepthOfScreen(s)	((s)->root_depth)
#define DefaultGCOfScreen(s)	((s)->default_gc)
#define DefaultVisualOfScreen(s)((s)->root_visual)
#define WidthOfScreen(s)	((s)->width)
#define HeightOfScreen(s)	((s)->height)
#define WidthMMOfScreen(s)	((s)->mwidth)
#define HeightMMOfScreen(s)	((s)->mheight)
#define PlanesOfScreen(s)	((s)->root_depth)
#define CellsOfScreen(s)	(DefaultVisualOfScreen((s))->map_entries)
#define MinCmapsOfScreen(s)	((s)->min_maps)
#define MaxCmapsOfScreen(s)	((s)->max_maps)
#define DoesSaveUnders(s)	((s)->save_unders)
#define DoesBackingStore(s)	((s)->backing_store)
#define EventMaskOfScreen(s)	((s)->root_input_mask)

/*
 * Extensions need a way to hang private data on some structures.
 */
typedef struct _XExtData {
	int number;		/* number returned by XRegisterExtension */
	struct _XExtData *next;	/* next item on list of data for structure */
	int (*free_private)();	/* called to free private storage */
	XPointer private_data;	/* data private to this extension. */
} XExtData;

/*
 * This file contains structures used by the extension mechanism.
 */
typedef struct {		/* public to extension, cannot be changed */
	int extension;		/* extension number */
	int major_opcode;	/* major op-code assigned by server */
	int first_event;	/* first event number for the extension */
	int first_error;	/* first error number for the extension */
} XExtCodes;

/*
 * Data structure for retrieving info about pixmap formats.
 */

typedef struct {
    int depth;
    int bits_per_pixel;
    int scanline_pad;
} XPixmapFormatValues;


/*
 * Data structure for setting graphics context.
 */
typedef struct {
	int function;		/* logical operation */
	unsigned long plane_mask;/* plane mask */
	unsigned long foreground;/* foreground pixel */
	unsigned long background;/* background pixel */
	int line_width;		/* line width */
	int line_style;	 	/* LineSolid, LineOnOffDash, LineDoubleDash */
	int cap_style;	  	/* CapNotLast, CapButt, 
				   CapRound, CapProjecting */
	int join_style;	 	/* JoinMiter, JoinRound, JoinBevel */
	int fill_style;	 	/* FillSolid, FillTiled, 
				   FillStippled, FillOpaeueStippled */
	int fill_rule;	  	/* EvenOddRule, WindingRule */
	int arc_mode;		/* ArcChord, ArcPieSlice */
	Pixmap tile;		/* tile pixmap for tiling operations */
	Pixmap stipple;		/* stipple 1 plane pixmap for stipping */
	int ts_x_origin;	/* offset for tile or stipple operations */
	int ts_y_origin;
        Font font;	        /* default text font for text operations */
	int subwindow_mode;     /* ClipByChildren, IncludeInferiors */
	Bool graphics_exposures;/* boolean, should exposures be generated */
	int clip_x_origin;	/* origin for clipping */
	int clip_y_origin;
	Pixmap clip_mask;	/* bitmap clipping; other calls for rects */
	int dash_offset;	/* patterned/dashed line information */
	char dashes;
} XGCValues;

/*
 * Graphics context.  The contents of this structure are implementation
 * dependent.  A GC should be treated as opaque by application code.
 */

typedef XGCValues *GC;

/*
 * Visual structure; contains information about colormapping possible.
 */
typedef struct {
	XExtData *ext_data;	/* hook for extension to hang data */
	VisualID visualid;	/* visual id of this visual */
#if defined(__cplusplus) || defined(c_plusplus)
	int c_class;		/* C++ class of screen (monochrome, etc.) */
#else
	int class;		/* class of screen (monochrome, etc.) */
#endif
	unsigned long red_mask, green_mask, blue_mask;	/* mask values */
	int bits_per_rgb;	/* log base 2 of distinct color values */
	int map_entries;	/* color map entries */
} Visual;

/*
 * Depth structure; contains information for each possible depth.
 */	
typedef struct {
	int depth;		/* this depth (Z) of the depth */
	int nvisuals;		/* number of Visual types at this depth */
	Visual *visuals;	/* list of visuals possible at this depth */
} Depth;

/*
 * Information about the screen.  The contents of this structure are
 * implementation dependent.  A Screen should be treated as opaque
 * by application code.
 */
typedef struct {
	XExtData *ext_data;	/* hook for extension to hang data */
	struct _XDisplay *display;/* back pointer to display structure */
	Window root;		/* Root window id. */
	int width, height;	/* width and height of screen */
	int mwidth, mheight;	/* width and height of  in millimeters */
	int ndepths;		/* number of depths possible */
	Depth *depths;		/* list of allowable depths on the screen */
	int root_depth;		/* bits per pixel */
	Visual *root_visual;	/* root visual */
	GC default_gc;		/* GC for the root root visual */
	Colormap cmap;		/* default color map */
	unsigned long white_pixel;
	unsigned long black_pixel;	/* White and Black pixel values */
	int max_maps, min_maps;	/* max and min color maps */
	int backing_store;	/* Never, WhenMapped, Always */
	Bool save_unders;	
	long root_input_mask;	/* initial root input mask */
} Screen;

/*
 * Format structure; describes ZFormat data the screen will understand.
 */
typedef struct {
	XExtData *ext_data;	/* hook for extension to hang data */
	int depth;		/* depth of this image format */
	int bits_per_pixel;	/* bits/pixel at this depth */
	int scanline_pad;	/* scanline must padded to this multiple */
} ScreenFormat;

/*
 * Data structure for setting window attributes.
 */
typedef struct {
    Pixmap background_pixmap;	/* background or None or ParentRelative */
    unsigned long background_pixel;	/* background pixel */
    Pixmap border_pixmap;	/* border of the window */
    unsigned long border_pixel;	/* border pixel value */
    int bit_gravity;		/* one of bit gravity values */
    int win_gravity;		/* one of the window gravity values */
    int backing_store;		/* NotUseful, WhenMapped, Always */
    unsigned long backing_planes;/* planes to be preseved if possible */
    unsigned long backing_pixel;/* value to use in restoring planes */
    Bool save_under;		/* should bits under be saved? (popups) */
    long event_mask;		/* set of events that should be saved */
    long do_not_propagate_mask;	/* set of events that should not propagate */
    Bool override_redirect;	/* boolean value for override-redirect */
    Colormap colormap;		/* color map to be associated with window */
    Cursor cursor;		/* cursor to be displayed (or None) */
} XSetWindowAttributes;

typedef struct {
    int x, y;			/* location of window */
    int width, height;		/* width and height of window */
    int border_width;		/* border width of window */
    int depth;          	/* depth of window */
    Visual *visual;		/* the associated visual structure */
    Window root;        	/* root of screen containing window */
#if defined(__cplusplus) || defined(c_plusplus)
    int c_class;		/* C++ InputOutput, InputOnly*/
#else
    int class;			/* InputOutput, InputOnly*/
#endif
    int bit_gravity;		/* one of bit gravity values */
    int win_gravity;		/* one of the window gravity values */
    int backing_store;		/* NotUseful, WhenMapped, Always */
    unsigned long backing_planes;/* planes to be preserved if possible */
    unsigned long backing_pixel;/* value to be used when restoring planes */
    Bool save_under;		/* boolean, should bits under be saved? */
    Colormap colormap;		/* color map to be associated with window */
    Bool map_installed;		/* boolean, is color map currently installed*/
    int map_state;		/* IsUnmapped, IsUnviewable, IsViewable */
    long all_event_masks;	/* set of events all people have interest in*/
    long your_event_mask;	/* my event mask */
    long do_not_propagate_mask; /* set of events that should not propagate */
    Bool override_redirect;	/* boolean value for override-redirect */
    Screen *screen;		/* back pointer to correct screen */
} XWindowAttributes;

/*
 * Data structure for host setting; getting routines.
 *
 */

typedef struct {
	int family;		/* for example FamilyInternet */
	int length;		/* length of address, in bytes */
	char *address;		/* pointer to where to find the bytes */
} XHostAddress;

/*
 * Data structure for "image" data, used by image manipulation routines.
 */
typedef struct _XImage {
    int width, height;		/* size of image */
    int xoffset;		/* number of pixels offset in X direction */
    int format;			/* XYBitmap, XYPixmap, ZPixmap */
    char *data;			/* pointer to image data */
    int byte_order;		/* data byte order, LSBFirst, MSBFirst */
    int bitmap_unit;		/* quant. of scanline 8, 16, 32 */
    int bitmap_bit_order;	/* LSBFirst, MSBFirst */
    int bitmap_pad;		/* 8, 16, 32 either XY or ZPixmap */
    int depth;			/* depth of image */
    int bytes_per_line;		/* accelarator to next line */
    int bits_per_pixel;		/* bits per pixel (ZPixmap) */
    unsigned long red_mask;	/* bits in z arrangment */
    unsigned long green_mask;
    unsigned long blue_mask;
    XPointer obdata;		/* hook for the object routines to hang on */
    struct funcs {		/* image manipulation routines */
	struct _XImage *(*create_image)();
#if NeedFunctionPrototypes
	int (*destroy_image)        (struct _XImage *);
	unsigned long (*get_pixel)  (struct _XImage *, int, int);
	int (*put_pixel)            (struct _XImage *, int, int, unsigned long);
	struct _XImage *(*sub_image)(struct _XImage *, int, int, unsigned int, unsigned int);
	int (*add_pixel)            (struct _XImage *, long);
#else
	int (*destroy_image)();
	unsigned long (*get_pixel)();
	int (*put_pixel)();
	struct _XImage *(*sub_image)();
	int (*add_pixel)();
#endif
	} f;
} XImage;

/* 
 * Data structure for XReconfigureWindow
 */
typedef struct {
    int x, y;
    int width, height;
    int border_width;
    Window sibling;
    int stack_mode;
} XWindowChanges;

/*
 * Data structure used by color operations
 */
typedef struct {
	unsigned long pixel;
	unsigned short red, green, blue;
	char flags;  /* do_red, do_green, do_blue */
	char pad;
} XColor;

/* 
 * Data structures for graphics operations.  On most machines, these are
 * congruent with the wire protocol structures, so reformatting the data
 * can be avoided on these architectures.
 */
typedef struct {
    short x1, y1, x2, y2;
} XSegment;

typedef struct {
    short x, y;
} XPoint;
    
typedef struct {
    short x, y;
    unsigned short width, height;
} XRectangle;
    
typedef struct {
    short x, y;
    unsigned short width, height;
    short angle1, angle2;
} XArc;


/* Data structure for XChangeKeyboardControl */

typedef struct {
        int key_click_percent;
        int bell_percent;
        int bell_pitch;
        int bell_duration;
        int led;
        int led_mode;
        int key;
        int auto_repeat_mode;   /* On, Off, Default */
} XKeyboardControl;

/* Data structure for XGetKeyboardControl */

typedef struct {
        int key_click_percent;
	int bell_percent;
	unsigned int bell_pitch, bell_duration;
	unsigned long led_mask;
	int global_auto_repeat;
	char auto_repeats[32];
} XKeyboardState;

/* Data structure for XGetMotionEvents.  */

typedef struct {
        Time time;
	short x, y;
} XTimeCoord;

/* Data structure for X{Set,Get}ModifierMapping */

typedef struct {
 	int max_keypermod;	/* The server's max # of keys per modifier */
 	KeyCode *modifiermap;	/* An 8 by max_keypermod array of modifiers */
} XModifierKeymap;


/*
 * Display datatype maintaining display specific data.
 * The contents of this structure are implementation dependent.
 * A Display should be treated as opaque by application code.
 */
typedef struct _XDisplay {
	XExtData *ext_data;	/* hook for extension to hang data */
	struct _XFreeFuncs *free_funcs; /* internal free functions */
	int fd;			/* Network socket. */
	int conn_checker;         /* ugly thing used by _XEventsQueued */
	int proto_major_version;/* maj. version of server's X protocol */
	int proto_minor_version;/* minor version of servers X protocol */
	char *vendor;		/* vendor of the server hardware */
        XID resource_base;	/* resource ID base */
	XID resource_mask;	/* resource ID mask bits */
	XID resource_id;	/* allocator current ID */
	int resource_shift;	/* allocator shift to correct bits */
	XID (*resource_alloc)(); /* allocator function */
	int byte_order;		/* screen byte order, LSBFirst, MSBFirst */
	int bitmap_unit;	/* padding and data requirements */
	int bitmap_pad;		/* padding requirements on bitmaps */
	int bitmap_bit_order;	/* LeastSignificant or MostSignificant */
	int nformats;		/* number of pixmap formats in list */
	ScreenFormat *pixmap_format;	/* pixmap format list */
	int vnumber;		/* Xlib's X protocol version number. */
	int release;		/* release of the server */
	struct _XSQEvent *head, *tail;	/* Input event queue. */
	int qlen;		/* Length of input event queue */
	unsigned long request;	/* sequence number of last request. */
	char *last_req;		/* beginning of last request, or dummy */
	char *buffer;		/* Output buffer starting address. */
	char *bufptr;		/* Output buffer index pointer. */
	char *bufmax;		/* Output buffer maximum+1 address. */
	unsigned max_request_size; /* maximum number 32 bit words in request*/
	struct _XrmHashBucketRec *db;
	int (*synchandler)();	/* Synchronization handler */
	char *display_name;	/* "host:display" string used on this connect*/
	int default_screen;	/* default screen for operations */
	int nscreens;		/* number of screens on this server*/
	Screen *screens;	/* pointer to list of screens */
	unsigned long motion_buffer;	/* size of motion buffer */
	unsigned long flags;	/* internal connection flags */
	int min_keycode;	/* minimum defined keycode */
	int max_keycode;	/* maximum defined keycode */
	KeySym *keysyms;	/* This server's keysyms */
	XModifierKeymap *modifiermap;	/* This server's modifier keymap */
	int keysyms_per_keycode;/* number of rows */
	char *xdefaults;	/* contents of defaults from server */
	char *scratch_buffer;	/* place to hang scratch buffer */
	unsigned long scratch_length;	/* length of scratch buffer */
	int ext_number;		/* extension number on this display */
	struct _XExten *ext_procs; /* extensions initialized on this display */
	/*
	 * the following can be fixed size, as the protocol defines how
	 * much address space is available. 
	 * While this could be done using the extension vector, there
	 * may be MANY events processed, so a search through the extension
	 * list to find the right procedure for each event might be
	 * expensive if many extensions are being used.
	 */
	Bool (*event_vec[128])();  /* vector for wire to event */
	Status (*wire_vec[128])(); /* vector for event to wire */
	KeySym lock_meaning;	   /* for XLookupString */
	struct _XLockInfo *lock;   /* multi-thread state, display lock */
	struct _XInternalAsync *async_handlers; /* for internal async */
	unsigned long bigreq_size; /* max size of big requests */
	struct _XLockPtrs *lock_fns; /* pointers to threads functions */
	/* things above this line should not move, for binary compatibility */
	struct _XKeytrans *key_bindings; /* for XLookupString */
	Font cursor_font;	   /* for XCreateFontCursor */
	struct _XDisplayAtoms *atoms; /* for XInternAtom */
	unsigned int mode_switch;  /* keyboard group modifiers */
	struct _XContextDB *context_db; /* context database */
	Bool (**error_vec)();      /* vector for wire to error */
	/*
	 * Xcms information
	 */
	struct {
	   XPointer defaultCCCs;  /* pointer to an array of default XcmsCCC */
	   XPointer clientCmaps;  /* pointer to linked list of XcmsCmapRec */
	   XPointer perVisualIntensityMaps;
				  /* linked list of XcmsIntensityMap */
	} cms;
	struct _XIMFilter *im_filters;
	struct _XSQEvent *qfree; /* unallocated event queue elements */
	unsigned long next_event_serial_num; /* inserted into next queue elt */
	int (*savedsynchandler)(); /* user synchandler when Xlib usurps */
} Display;

#if NeedFunctionPrototypes	/* prototypes require event type definitions */
#undef _XEVENT_
#endif
#ifndef _XEVENT_

#define XMaxTransChars 4

/*
 * Definitions of specific events.
 */
typedef struct {
	int type;		/* of event */
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window window;	        /* "event" window it is reported relative to */
	Window root;	        /* root window that the event occured on */
	Window subwindow;	/* child window */
	Time time;		/* milliseconds */
	int x, y;		/* pointer x, y coordinates in event window */
	int x_root, y_root;	/* coordinates relative to root */
	unsigned int state;	/* key or button mask */
	unsigned int keycode;	/* detail */
	Bool same_screen;	/* same screen flag */
        char trans_chars[XMaxTransChars];
				/* translated characters */
	int nbytes;
} XKeyEvent;
typedef XKeyEvent XKeyPressedEvent;
typedef XKeyEvent XKeyReleasedEvent;

typedef struct {
	int type;		/* of event */
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window window;	        /* "event" window it is reported relative to */
	Window root;	        /* root window that the event occured on */
	Window subwindow;	/* child window */
	Time time;		/* milliseconds */
	int x, y;		/* pointer x, y coordinates in event window */
	int x_root, y_root;	/* coordinates relative to root */
	unsigned int state;	/* key or button mask */
	unsigned int button;	/* detail */
	Bool same_screen;	/* same screen flag */
} XButtonEvent;
typedef XButtonEvent XButtonPressedEvent;
typedef XButtonEvent XButtonReleasedEvent;

typedef struct {
	int type;		/* of event */
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window window;	        /* "event" window reported relative to */
	Window root;	        /* root window that the event occured on */
	Window subwindow;	/* child window */
	Time time;		/* milliseconds */
	int x, y;		/* pointer x, y coordinates in event window */
	int x_root, y_root;	/* coordinates relative to root */
	unsigned int state;	/* key or button mask */
	char is_hint;		/* detail */
	Bool same_screen;	/* same screen flag */
} XMotionEvent;
typedef XMotionEvent XPointerMovedEvent;

typedef struct {
	int type;		/* of event */
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window window;	        /* "event" window reported relative to */
	Window root;	        /* root window that the event occured on */
	Window subwindow;	/* child window */
	Time time;		/* milliseconds */
	int x, y;		/* pointer x, y coordinates in event window */
	int x_root, y_root;	/* coordinates relative to root */
	int mode;		/* NotifyNormal, NotifyGrab, NotifyUngrab */
	int detail;
	/*
	 * NotifyAncestor, NotifyVirtual, NotifyInferior, 
	 * NotifyNonlinear,NotifyNonlinearVirtual
	 */
	Bool same_screen;	/* same screen flag */
	Bool focus;		/* boolean focus */
	unsigned int state;	/* key or button mask */
} XCrossingEvent;
typedef XCrossingEvent XEnterWindowEvent;
typedef XCrossingEvent XLeaveWindowEvent;

typedef struct {
	int type;		/* FocusIn or FocusOut */
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window window;		/* window of event */
	int mode;		/* NotifyNormal, NotifyGrab, NotifyUngrab */
	int detail;
	/*
	 * NotifyAncestor, NotifyVirtual, NotifyInferior, 
	 * NotifyNonlinear,NotifyNonlinearVirtual, NotifyPointer,
	 * NotifyPointerRoot, NotifyDetailNone 
	 */
} XFocusChangeEvent;
typedef XFocusChangeEvent XFocusInEvent;
typedef XFocusChangeEvent XFocusOutEvent;

/* generated on EnterWindow and FocusIn  when KeyMapState selected */
typedef struct {
	int type;
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window window;
	char key_vector[32];
} XKeymapEvent;	

typedef struct {
	int type;
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window window;
	int x, y;
	int width, height;
	int count;		/* if non-zero, at least this many more */
} XExposeEvent;

typedef struct {
	int type;
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Drawable drawable;
	int x, y;
	int width, height;
	int count;		/* if non-zero, at least this many more */
	int major_code;		/* core is CopyArea or CopyPlane */
	int minor_code;		/* not defined in the core */
} XGraphicsExposeEvent;

typedef struct {
	int type;
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Drawable drawable;
	int major_code;		/* core is CopyArea or CopyPlane */
	int minor_code;		/* not defined in the core */
} XNoExposeEvent;

typedef struct {
	int type;
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window window;
	int state;		/* Visibility state */
} XVisibilityEvent;

typedef struct {
	int type;
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window parent;		/* parent of the window */
	Window window;		/* window id of window created */
	int x, y;		/* window location */
	int width, height;	/* size of window */
	int border_width;	/* border width */
	Bool override_redirect;	/* creation should be overridden */
} XCreateWindowEvent;

typedef struct {
	int type;
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window event;
	Window window;
} XDestroyWindowEvent;

typedef struct {
	int type;
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window event;
	Window window;
	Bool from_configure;
} XUnmapEvent;

typedef struct {
	int type;
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window event;
	Window window;
	Bool override_redirect;	/* boolean, is override set... */
} XMapEvent;

typedef struct {
	int type;
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window parent;
	Window window;
} XMapRequestEvent;

typedef struct {
	int type;
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window event;
	Window window;
	Window parent;
	int x, y;
	Bool override_redirect;
} XReparentEvent;

typedef struct {
	int type;
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window event;
	Window window;
	int x, y;
	int width, height;
	int border_width;
	Window above;
	Bool override_redirect;
} XConfigureEvent;

typedef struct {
	int type;
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window event;
	Window window;
	int x, y;
} XGravityEvent;

typedef struct {
	int type;
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window window;
	int width, height;
} XResizeRequestEvent;

typedef struct {
	int type;
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window parent;
	Window window;
	int x, y;
	int width, height;
	int border_width;
	Window above;
	int detail;		/* Above, Below, TopIf, BottomIf, Opposite */
	unsigned long value_mask;
} XConfigureRequestEvent;

typedef struct {
	int type;
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window event;
	Window window;
	int place;		/* PlaceOnTop, PlaceOnBottom */
} XCirculateEvent;

typedef struct {
	int type;
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window parent;
	Window window;
	int place;		/* PlaceOnTop, PlaceOnBottom */
} XCirculateRequestEvent;

typedef struct {
	int type;
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window window;
	Atom atom;
	Time time;
	int state;		/* NewValue, Deleted */
} XPropertyEvent;

typedef struct {
	int type;
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window window;
	Atom selection;
	Time time;
} XSelectionClearEvent;

typedef struct {
	int type;
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window owner;
	Window requestor;
	Atom selection;
	Atom target;
	Atom property;
	Time time;
} XSelectionRequestEvent;

typedef struct {
	int type;
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window requestor;
	Atom selection;
	Atom target;
	Atom property;		/* ATOM or None */
	Time time;
} XSelectionEvent;

typedef struct {
	int type;
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window window;
	Colormap colormap;	/* COLORMAP or None */
#if defined(__cplusplus) || defined(c_plusplus)
	Bool c_new;		/* C++ */
#else
	Bool new;
#endif
	int state;		/* ColormapInstalled, ColormapUninstalled */
} XColormapEvent;

typedef struct {
	int type;
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window window;
	Atom message_type;
	int format;
	union {
		char b[20];
		short s[10];
		long l[5];
		} data;
} XClientMessageEvent;

typedef struct {
	int type;
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;	/* Display the event was read from */
	Window window;		/* unused */
	int request;		/* one of MappingModifier, MappingKeyboard,
				   MappingPointer */
	int first_keycode;	/* first keycode */
	int count;		/* defines range of change w. first_keycode*/
} XMappingEvent;

typedef struct {
	int type;
	Display *display;	/* Display the event was read from */
	XID resourceid;		/* resource id */
	unsigned long serial;	/* serial number of failed request */
	unsigned char error_code;	/* error code of failed request */
	unsigned char request_code;	/* Major op-code of failed request */
	unsigned char minor_code;	/* Minor op-code of failed request */
} XErrorEvent;

typedef struct {
	int type;
	unsigned long serial;	/* # of last request processed by server */
	Bool send_event;	/* true if this came from a SendEvent request */
	Display *display;/* Display the event was read from */
	Window window;	/* window on which event was requested in event mask */
} XAnyEvent;

/*
 * this union is defined so Xlib can always use the same sized
 * event structure internally, to avoid memory fragmentation.
 */
typedef union _XEvent {
        int type;		/* must not be changed; first element */
	XAnyEvent xany;
	XKeyEvent xkey;
	XButtonEvent xbutton;
	XMotionEvent xmotion;
	XCrossingEvent xcrossing;
	XFocusChangeEvent xfocus;
	XExposeEvent xexpose;
	XGraphicsExposeEvent xgraphicsexpose;
	XNoExposeEvent xnoexpose;
	XVisibilityEvent xvisibility;
	XCreateWindowEvent xcreatewindow;
	XDestroyWindowEvent xdestroywindow;
	XUnmapEvent xunmap;
	XMapEvent xmap;
	XMapRequestEvent xmaprequest;
	XReparentEvent xreparent;
	XConfigureEvent xconfigure;
	XGravityEvent xgravity;
	XResizeRequestEvent xresizerequest;
	XConfigureRequestEvent xconfigurerequest;
	XCirculateEvent xcirculate;
	XCirculateRequestEvent xcirculaterequest;
	XPropertyEvent xproperty;
	XSelectionClearEvent xselectionclear;
	XSelectionRequestEvent xselectionrequest;
	XSelectionEvent xselection;
	XColormapEvent xcolormap;
	XClientMessageEvent xclient;
	XMappingEvent xmapping;
	XErrorEvent xerror;
	XKeymapEvent xkeymap;
	long pad[24];
} XEvent;
#endif

#define XAllocID(dpy) ((*(dpy)->resource_alloc)((dpy)))

/*
 * per character font metric information.
 */
typedef struct {
    short	lbearing;	/* origin to left edge of raster */
    short	rbearing;	/* origin to right edge of raster */
    short	width;		/* advance to next char's origin */
    short	ascent;		/* baseline to top edge of raster */
    short	descent;	/* baseline to bottom edge of raster */
    unsigned short attributes;	/* per char flags (not predefined) */
} XCharStruct;

/*
 * To allow arbitrary information with fonts, there are additional properties
 * returned.
 */
typedef struct {
    Atom name;
    unsigned long card32;
} XFontProp;

typedef struct {
    XExtData	*ext_data;	/* hook for extension to hang data */
    Font        fid;            /* Font id for this font */
    unsigned	direction;	/* hint about direction the font is painted */
    unsigned	min_char_or_byte2;/* first character */
    unsigned	max_char_or_byte2;/* last character */
    unsigned	min_byte1;	/* first row that exists */
    unsigned	max_byte1;	/* last row that exists */
    Bool	all_chars_exist;/* flag if all characters have non-zero size*/
    unsigned	default_char;	/* char to print for undefined character */
    int         n_properties;   /* how many properties there are */
    XFontProp	*properties;	/* pointer to array of additional properties*/
    XCharStruct	min_bounds;	/* minimum bounds over all existing char*/
    XCharStruct	max_bounds;	/* maximum bounds over all existing char*/
    XCharStruct	*per_char;	/* first_char to last_char information */
    int		ascent;		/* log. extent above baseline for spacing */
    int		descent;	/* log. descent below baseline for spacing */
} XFontStruct;

/*
 * PolyText routines take these as arguments.
 */
typedef struct {
    char *chars;		/* pointer to string */
    int nchars;			/* number of characters */
    int delta;			/* delta between strings */
    Font font;			/* font to print it in, None don't change */
} XTextItem;

typedef struct {		/* normal 16 bit characters are two bytes */
    unsigned char byte1;
    unsigned char byte2;
} XChar2b;

typedef struct {
    XChar2b *chars;		/* two byte characters */
    int nchars;			/* number of characters */
    int delta;			/* delta between strings */
    Font font;			/* font to print it in, None don't change */
} XTextItem16;


typedef union { Display *display;
		GC gc;
		Visual *visual;
		Screen *screen;
		ScreenFormat *pixmap_format;
		XFontStruct *font; } XEDataObject;

typedef struct {
    XRectangle      max_ink_extent;
    XRectangle      max_logical_extent;
} XFontSetExtents;

typedef struct _XFontSet *XFontSet;

typedef struct {
    char           *chars;
    int             nchars;
    int             delta;
    XFontSet        font_set;
} XmbTextItem;

typedef struct {
    wchar_t        *chars;
    int             nchars;
    int             delta;
    XFontSet        font_set;
} XwcTextItem;

typedef void (*XIMProc)();

typedef struct _XIM *XIM;
typedef struct _XIC *XIC;

typedef unsigned long XIMStyle;

typedef struct {
    unsigned short count_styles;
    XIMStyle *supported_styles;
} XIMStyles;

#define XIMPreeditArea		0x0001L
#define XIMPreeditCallbacks	0x0002L
#define XIMPreeditPosition	0x0004L
#define XIMPreeditNothing	0x0008L
#define XIMPreeditNone		0x0010L
#define XIMStatusArea		0x0100L
#define XIMStatusCallbacks	0x0200L
#define XIMStatusNothing	0x0400L
#define XIMStatusNone		0x0800L

#define XNVaNestedList "XNVaNestedList"
#define XNClientWindow "clientWindow"
#define XNInputStyle "inputStyle"
#define XNFocusWindow "focusWindow"
#define XNResourceName "resourceName"
#define XNResourceClass "resourceClass"
#define XNGeometryCallback "geometryCallback"
#define XNFilterEvents "filterEvents"
#define XNPreeditStartCallback "preeditStartCallback"
#define XNPreeditDoneCallback "preeditDoneCallback"
#define XNPreeditDrawCallback "preeditDrawCallback"
#define XNPreeditCaretCallback "preeditCaretCallback"
#define XNPreeditAttributes "preeditAttributes"
#define XNStatusStartCallback "statusStartCallback"
#define XNStatusDoneCallback "statusDoneCallback"
#define XNStatusDrawCallback "statusDrawCallback"
#define XNStatusAttributes "statusAttributes"
#define XNArea "area"
#define XNAreaNeeded "areaNeeded"
#define XNSpotLocation "spotLocation"
#define XNColormap "colorMap"
#define XNStdColormap "stdColorMap"
#define XNForeground "foreground"
#define XNBackground "background"
#define XNBackgroundPixmap "backgroundPixmap"
#define XNFontSet "fontSet"
#define XNLineSpace "lineSpace"
#define XNCursor "cursor"

#define XBufferOverflow		-1
#define XLookupNone		1
#define XLookupChars		2
#define XLookupKeySym		3
#define XLookupBoth		4

#if NeedFunctionPrototypes
typedef void *XVaNestedList;
#else
typedef XPointer XVaNestedList;
#endif

typedef struct {
    XPointer client_data;
    XIMProc callback;
} XIMCallback;

typedef unsigned long XIMFeedback;

#define XIMReverse	1
#define XIMUnderline	(1<<1) 
#define XIMHighlight	(1<<2)
#define XIMPrimary 	(1<<5)
#define XIMSecondary	(1<<6)
#define XIMTertiary 	(1<<7)

typedef struct _XIMText {
    unsigned short length;
    XIMFeedback *feedback;
    Bool encoding_is_wchar; 
    union {
	char *multi_byte;
	wchar_t *wide_char;
    } string; 
} XIMText;

typedef struct _XIMPreeditDrawCallbackStruct {
    int caret;		/* Cursor offset within pre-edit string */
    int chg_first;	/* Starting change position */
    int chg_length;	/* Length of the change in character count */
    XIMText *text;
} XIMPreeditDrawCallbackStruct;

typedef enum {
    XIMForwardChar, XIMBackwardChar,
    XIMForwardWord, XIMBackwardWord,
    XIMCaretUp, XIMCaretDown,
    XIMNextLine, XIMPreviousLine,
    XIMLineStart, XIMLineEnd, 
    XIMAbsolutePosition,
    XIMDontChange
} XIMCaretDirection;

typedef enum {
    XIMIsInvisible,	/* Disable caret feedback */ 
    XIMIsPrimary,	/* UI defined caret feedback */
    XIMIsSecondary	/* UI defined caret feedback */
} XIMCaretStyle;

typedef struct _XIMPreeditCaretCallbackStruct {
    int position;		 /* Caret offset within pre-edit string */
    XIMCaretDirection direction; /* Caret moves direction */
    XIMCaretStyle style;	 /* Feedback of the caret */
} XIMPreeditCaretCallbackStruct;

typedef enum {
    XIMTextType,
    XIMBitmapType
} XIMStatusDataType;
	
typedef struct _XIMStatusDrawCallbackStruct {
    XIMStatusDataType type;
    union {
	XIMText *text;
	Pixmap  bitmap;
    } data;
} XIMStatusDrawCallbackStruct;

typedef int (*XErrorHandler) (	    /* WARNING, this type not in Xlib spec */
#if NeedFunctionPrototypes
    Display*		/* display */,
    XErrorEvent*	/* error_event */
#endif
);

_XFUNCPROTOBEGIN



#include "tkIntXlibDecls.h"

_XFUNCPROTOEND

#if defined(MAC_OSX_TK)
#   undef Cursor
#   undef Region
#endif

#endif /* _XLIB_H_ */
/* $XConsortium: Xutil.h,v 11.73 91/07/30 16:21:37 rws Exp $ */

/***********************************************************
Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts,
and the Massachusetts Institute of Technology, Cambridge, Massachusetts.

                        All Rights Reserved

Permission to use, copy, modify, and distribute this software and its 
documentation for any purpose and without fee is hereby granted, 
provided that the above copyright notice appear in all copies and that
both that copyright notice and this permission notice appear in 
supporting documentation, and that the names of Digital or MIT not be
used in advertising or publicity pertaining to distribution of the
software without specific, written prior permission.  

DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL
DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR
ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
SOFTWARE.

******************************************************************/

#ifndef _XUTIL_H_
#define _XUTIL_H_

/* You must include <X11/Xlib.h> before including this file */

#if defined(MAC_OSX_TK)
#   define Region XRegion
#endif

/* 
 * Bitmask returned by XParseGeometry().  Each bit tells if the corresponding
 * value (x, y, width, height) was found in the parsed string.
 */
#define NoValue		0x0000
#define XValue  	0x0001
#define YValue		0x0002
#define WidthValue  	0x0004
#define HeightValue  	0x0008
#define AllValues 	0x000F
#define XNegative 	0x0010
#define YNegative 	0x0020

/*
 * new version containing base_width, base_height, and win_gravity fields;
 * used with WM_NORMAL_HINTS.
 */
typedef struct {
    	long flags;	/* marks which fields in this structure are defined */
	int x, y;		/* obsolete for new window mgrs, but clients */
	int width, height;	/* should set so old wm's don't mess up */
	int min_width, min_height;
	int max_width, max_height;
    	int width_inc, height_inc;
	struct {
		int x;	/* numerator */
		int y;	/* denominator */
	} min_aspect, max_aspect;
	int base_width, base_height;		/* added by ICCCM version 1 */
	int win_gravity;			/* added by ICCCM version 1 */
} XSizeHints;

/*
 * The next block of definitions are for window manager properties that
 * clients and applications use for communication.
 */

/* flags argument in size hints */
#define USPosition	(1L << 0) /* user specified x, y */
#define USSize		(1L << 1) /* user specified width, height */

#define PPosition	(1L << 2) /* program specified position */
#define PSize		(1L << 3) /* program specified size */
#define PMinSize	(1L << 4) /* program specified minimum size */
#define PMaxSize	(1L << 5) /* program specified maximum size */
#define PResizeInc	(1L << 6) /* program specified resize increments */
#define PAspect		(1L << 7) /* program specified min and max aspect ratios */
#define PBaseSize	(1L << 8) /* program specified base for incrementing */
#define PWinGravity	(1L << 9) /* program specified window gravity */

/* obsolete */
#define PAllHints (PPosition|PSize|PMinSize|PMaxSize|PResizeInc|PAspect)



typedef struct {
	long flags;	/* marks which fields in this structure are defined */
	Bool input;	/* does this application rely on the window manager to
			get keyboard input? */
	int initial_state;	/* see below */
	Pixmap icon_pixmap;	/* pixmap to be used as icon */
	Window icon_window; 	/* window to be used as icon */
	int icon_x, icon_y; 	/* initial position of icon */
	Pixmap icon_mask;	/* icon mask bitmap */
	XID window_group;	/* id of related window group */
	/* this structure may be extended in the future */
} XWMHints;

/* definition for flags of XWMHints */

#define InputHint 		(1L << 0)
#define StateHint 		(1L << 1)
#define IconPixmapHint		(1L << 2)
#define IconWindowHint		(1L << 3)
#define IconPositionHint 	(1L << 4)
#define IconMaskHint		(1L << 5)
#define WindowGroupHint		(1L << 6)
#define AllHints (InputHint|StateHint|IconPixmapHint|IconWindowHint| \
IconPositionHint|IconMaskHint|WindowGroupHint)

/* definitions for initial window state */
#define WithdrawnState 0	/* for windows that are not mapped */
#define NormalState 1	/* most applications want to start this way */
#define IconicState 3	/* application wants to start as an icon */

/*
 * Obsolete states no longer defined by ICCCM
 */
#define DontCareState 0	/* don't know or care */
#define ZoomState 2	/* application wants to start zoomed */
#define InactiveState 4	/* application believes it is seldom used; */
			/* some wm's may put it on inactive menu */


/*
 * new structure for manipulating TEXT properties; used with WM_NAME, 
 * WM_ICON_NAME, WM_CLIENT_MACHINE, and WM_COMMAND.
 */
typedef struct {
    unsigned char *value;		/* same as Property routines */
    Atom encoding;			/* prop type */
    int format;				/* prop data format: 8, 16, or 32 */
    unsigned long nitems;		/* number of data items in value */
} XTextProperty;

#define XNoMemory -1
#define XLocaleNotSupported -2
#define XConverterNotFound -3

typedef enum {
    XStringStyle,		/* STRING */
    XCompoundTextStyle,		/* COMPOUND_TEXT */
    XTextStyle,			/* text in owner's encoding (current locale)*/
    XStdICCTextStyle		/* STRING, else COMPOUND_TEXT */
} XICCEncodingStyle;

typedef struct {
	int min_width, min_height;
	int max_width, max_height;
	int width_inc, height_inc;
} XIconSize;

typedef struct {
	char *res_name;
	char *res_class;
} XClassHint;

/*
 * These macros are used to give some sugar to the image routines so that
 * naive people are more comfortable with them.
 */
#define XDestroyImage(ximage) \
	((*((ximage)->f.destroy_image))((ximage)))
#define XGetPixel(ximage, x, y) \
	((*((ximage)->f.get_pixel))((ximage), (x), (y)))
#define XPutPixel(ximage, x, y, pixel) \
	((*((ximage)->f.put_pixel))((ximage), (x), (y), (pixel)))
#define XSubImage(ximage, x, y, width, height)  \
	((*((ximage)->f.sub_image))((ximage), (x), (y), (width), (height)))
#define XAddPixel(ximage, value) \
	((*((ximage)->f.add_pixel))((ximage), (value)))

/*
 * Compose sequence status structure, used in calling XLookupString.
 */
typedef struct _XComposeStatus {
    XPointer compose_ptr;	/* state table pointer */
    int chars_matched;		/* match state */
} XComposeStatus;

/*
 * Keysym macros, used on Keysyms to test for classes of symbols
 */
#define IsKeypadKey(keysym) \
  (((unsigned)(keysym) >= XK_KP_Space) && ((unsigned)(keysym) <= XK_KP_Equal))

#define IsCursorKey(keysym) \
  (((unsigned)(keysym) >= XK_Home)     && ((unsigned)(keysym) <  XK_Select))

#define IsPFKey(keysym) \
  (((unsigned)(keysym) >= XK_KP_F1)     && ((unsigned)(keysym) <= XK_KP_F4))

#define IsFunctionKey(keysym) \
  (((unsigned)(keysym) >= XK_F1)       && ((unsigned)(keysym) <= XK_F35))

#define IsMiscFunctionKey(keysym) \
  (((unsigned)(keysym) >= XK_Select)   && ((unsigned)(keysym) <= XK_Break))

#define IsModifierKey(keysym) \
  ((((unsigned)(keysym) >= XK_Shift_L) && ((unsigned)(keysym) <= XK_Hyper_R)) \
   || ((unsigned)(keysym) == XK_Mode_switch) \
   || ((unsigned)(keysym) == XK_Num_Lock))
/*
 * opaque reference to Region data type 
 */
typedef struct _XRegion *Region; 

/* Return values from XRectInRegion() */
 
#define RectangleOut 0
#define RectangleIn  1
#define RectanglePart 2
 

/*
 * Information used by the visual utility routines to find desired visual
 * type from the many visuals a display may support.
 */

typedef struct {
  Visual *visual;
  VisualID visualid;
  int screen;
  int depth;
#if defined(__cplusplus) || defined(c_plusplus)
  int c_class;					/* C++ */
#else
  int class;
#endif
  unsigned long red_mask;
  unsigned long green_mask;
  unsigned long blue_mask;
  int colormap_size;
  int bits_per_rgb;
} XVisualInfo;

#define VisualNoMask		0x0
#define VisualIDMask 		0x1
#define VisualScreenMask	0x2
#define VisualDepthMask		0x4
#define VisualClassMask		0x8
#define VisualRedMaskMask	0x10
#define VisualGreenMaskMask	0x20
#define VisualBlueMaskMask	0x40
#define VisualColormapSizeMask	0x80
#define VisualBitsPerRGBMask	0x100
#define VisualAllMask		0x1FF

/*
 * This defines a window manager property that clients may use to
 * share standard color maps of type RGB_COLOR_MAP:
 */
typedef struct {
	Colormap colormap;
	unsigned long red_max;
	unsigned long red_mult;
	unsigned long green_max;
	unsigned long green_mult;
	unsigned long blue_max;
	unsigned long blue_mult;
	unsigned long base_pixel;
	VisualID visualid;		/* added by ICCCM version 1 */
	XID killid;			/* added by ICCCM version 1 */
} XStandardColormap;

#define ReleaseByFreeingColormap ((XID) 1L)  /* for killid field above */


/*
 * return codes for XReadBitmapFile and XWriteBitmapFile
 */
#define BitmapSuccess		0
#define BitmapOpenFailed 	1
#define BitmapFileInvalid 	2
#define BitmapNoMemory		3

/****************************************************************
 *
 * Context Management
 *
 ****************************************************************/


/* Associative lookup table return codes */

#define XCSUCCESS 0	/* No error. */
#define XCNOMEM   1    /* Out of memory */
#define XCNOENT   2    /* No entry in table */

typedef int XContext;

#define XUniqueContext()       ((XContext) XrmUniqueQuark())
#define XStringToContext(string)   ((XContext) XrmStringToQuark(string))

_XFUNCPROTOBEGIN

/* The following declarations are alphabetized. */

extern XClassHint *XAllocClassHint (
#if NeedFunctionPrototypes
    void
#endif
);

extern XIconSize *XAllocIconSize (
#if NeedFunctionPrototypes
    void
#endif
);

extern XSizeHints *XAllocSizeHints (
#if NeedFunctionPrototypes
    void
#endif
);

extern XStandardColormap *XAllocStandardColormap (
#if NeedFunctionPrototypes
    void
#endif
);

extern XWMHints *XAllocWMHints (
#if NeedFunctionPrototypes
    void
#endif
);

extern void XClipBox(
#if NeedFunctionPrototypes
    Region		/* r */,
    XRectangle*		/* rect_return */
#endif
);

extern Region XCreateRegion(
#if NeedFunctionPrototypes
    void
#endif
);

extern char *XDefaultString(
#if NeedFunctionPrototypes
    void
#endif
);

extern int XDeleteContext(
#if NeedFunctionPrototypes
    Display*		/* display */,
    XID			/* rid */,
    XContext		/* context */
#endif
);

extern void XDestroyRegion(
#if NeedFunctionPrototypes
    Region		/* r */
#endif
);

extern void XEmptyRegion(
#if NeedFunctionPrototypes
    Region		/* r */
#endif
);

extern void XEqualRegion(
#if NeedFunctionPrototypes
    Region		/* r1 */,
    Region		/* r2 */
#endif
);

extern int XFindContext(
#if NeedFunctionPrototypes
    Display*		/* display */,
    XID			/* rid */,
    XContext		/* context */,
    XPointer*		/* data_return */
#endif
);

extern Status XGetClassHint(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    XClassHint*		/* class_hints_return */
#endif
);

extern Status XGetIconSizes(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    XIconSize**		/* size_list_return */,
    int*		/* count_return */
#endif
);

extern Status XGetNormalHints(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    XSizeHints*		/* hints_return */
#endif
);

extern Status XGetRGBColormaps(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    XStandardColormap** /* stdcmap_return */,
    int*		/* count_return */,
    Atom		/* property */
#endif
);

extern Status XGetSizeHints(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    XSizeHints*		/* hints_return */,
    Atom		/* property */
#endif
);

extern Status XGetStandardColormap(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    XStandardColormap*	/* colormap_return */,
    Atom		/* property */			    
#endif
);

extern Status XGetTextProperty(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* window */,
    XTextProperty*	/* text_prop_return */,
    Atom		/* property */
#endif
);


extern Status XGetWMClientMachine(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    XTextProperty*	/* text_prop_return */
#endif
);

extern XWMHints *XGetWMHints(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */		      
#endif
);

extern Status XGetWMIconName(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    XTextProperty*	/* text_prop_return */
#endif
);

extern Status XGetWMName(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    XTextProperty*	/* text_prop_return */
#endif
);

extern Status XGetWMNormalHints(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    XSizeHints*		/* hints_return */,
    long*		/* supplied_return */ 
#endif
);

extern Status XGetWMSizeHints(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    XSizeHints*		/* hints_return */,
    long*		/* supplied_return */,
    Atom		/* property */
#endif
);

extern Status XGetZoomHints(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    XSizeHints*		/* zhints_return */
#endif
);

extern void XIntersectRegion(
#if NeedFunctionPrototypes
    Region		/* sra */,
    Region		/* srb */,
    Region		/* dr_return */
#endif
);

extern int XLookupString(
#if NeedFunctionPrototypes
    XKeyEvent*		/* event_struct */,
    char*		/* buffer_return */,
    int			/* bytes_buffer */,
    KeySym*		/* keysym_return */,
    XComposeStatus*	/* status_in_out */
#endif
);

extern Status XMatchVisualInfo(
#if NeedFunctionPrototypes
    Display*		/* display */,
    int			/* screen */,
    int			/* depth */,
    int			/* class */,
    XVisualInfo*	/* vinfo_return */
#endif
);

extern void XOffsetRegion(
#if NeedFunctionPrototypes
    Region		/* r */,
    int			/* dx */,
    int			/* dy */
#endif
);

extern Bool XPointInRegion(
#if NeedFunctionPrototypes
    Region		/* r */,
    int			/* x */,
    int			/* y */
#endif
);

extern Region XPolygonRegion(
#if NeedFunctionPrototypes
    XPoint*		/* points */,
    int			/* n */,
    int			/* fill_rule */
#endif
);

extern int XRectInRegion(
#if NeedFunctionPrototypes
    Region		/* r */,
    int			/* x */,
    int			/* y */,
    unsigned int	/* width */,
    unsigned int	/* height */
#endif
);

extern int XSaveContext(
#if NeedFunctionPrototypes
    Display*		/* display */,
    XID			/* rid */,
    XContext		/* context */,
    _Xconst char*	/* data */
#endif
);

extern void XSetClassHint(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    XClassHint*		/* class_hints */
#endif
);

extern void XSetIconSizes(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    XIconSize*		/* size_list */,
    int			/* count */    
#endif
);

extern void XSetNormalHints(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    XSizeHints*		/* hints */
#endif
);

extern void XSetRGBColormaps(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    XStandardColormap*	/* stdcmaps */,
    int			/* count */,
    Atom		/* property */
#endif
);

extern void XSetSizeHints(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    XSizeHints*		/* hints */,
    Atom		/* property */
#endif
);

extern void XSetStandardProperties(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    _Xconst char*	/* window_name */,
    _Xconst char*	/* icon_name */,
    Pixmap		/* icon_pixmap */,
    char**		/* argv */,
    int			/* argc */,
    XSizeHints*		/* hints */
#endif
);

extern void XSetTextProperty(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    XTextProperty*	/* text_prop */,
    Atom		/* property */
#endif
);

extern void XSetWMHints(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    XWMHints*		/* wm_hints */
#endif
);

extern void XSetWMIconName(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    XTextProperty*	/* text_prop */
#endif
);

extern void XSetWMName(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    XTextProperty*	/* text_prop */
#endif
);

extern void XSetWMNormalHints(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    XSizeHints*		/* hints */
#endif
);

extern void XSetWMProperties(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    XTextProperty*	/* window_name */,
    XTextProperty*	/* icon_name */,
    char**		/* argv */,
    int			/* argc */,
    XSizeHints*		/* normal_hints */,
    XWMHints*		/* wm_hints */,
    XClassHint*		/* class_hints */
#endif
);

extern void XmbSetWMProperties(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    _Xconst char*	/* window_name */,
    _Xconst char*	/* icon_name */,
    char**		/* argv */,
    int			/* argc */,
    XSizeHints*		/* normal_hints */,
    XWMHints*		/* wm_hints */,
    XClassHint*		/* class_hints */
#endif
);

extern void XSetWMSizeHints(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    XSizeHints*		/* hints */,
    Atom		/* property */
#endif
);

extern void XSetRegion(
#if NeedFunctionPrototypes
    Display*		/* display */,
    GC			/* gc */,
    Region		/* r */
#endif
);

extern void XSetStandardColormap(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    XStandardColormap*	/* colormap */,
    Atom		/* property */
#endif
);

extern void XSetZoomHints(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* w */,
    XSizeHints*		/* zhints */
#endif
);

extern void XShrinkRegion(
#if NeedFunctionPrototypes
    Region		/* r */,
    int			/* dx */,
    int			/* dy */
#endif
);

extern void XSubtractRegion(
#if NeedFunctionPrototypes
    Region		/* sra */,
    Region		/* srb */,
    Region		/* dr_return */
#endif
);

extern int XmbTextListToTextProperty(
#if NeedFunctionPrototypes
    Display*		/* display */,
    char**		/* list */,
    int			/* count */,
    XICCEncodingStyle	/* style */,
    XTextProperty*	/* text_prop_return */
#endif
);

extern int XwcTextListToTextProperty(
#if NeedFunctionPrototypes
    Display*		/* display */,
    wchar_t**		/* list */,
    int			/* count */,
    XICCEncodingStyle	/* style */,
    XTextProperty*	/* text_prop_return */
#endif
);

extern void XwcFreeStringList(
#if NeedFunctionPrototypes
    wchar_t**		/* list */
#endif
);

extern Status XTextPropertyToStringList(
#if NeedFunctionPrototypes
    XTextProperty*	/* text_prop */,
    char***		/* list_return */,
    int*		/* count_return */
#endif
);

extern int XmbTextPropertyToTextList(
#if NeedFunctionPrototypes
    Display*		/* display */,
    XTextProperty*	/* text_prop */,
    char***		/* list_return */,
    int*		/* count_return */
#endif
);

extern int XwcTextPropertyToTextList(
#if NeedFunctionPrototypes
    Display*		/* display */,
    XTextProperty*	/* text_prop */,
    wchar_t***		/* list_return */,
    int*		/* count_return */
#endif
);

extern void XUnionRectWithRegion(
#if NeedFunctionPrototypes
    XRectangle*		/* rectangle */,
    Region		/* src_region */,
    Region		/* dest_region_return */
#endif
);

extern void XUnionRegion(
#if NeedFunctionPrototypes
    Region		/* sra */,
    Region		/* srb */,
    Region		/* dr_return */
#endif
);

extern int XWMGeometry(
#if NeedFunctionPrototypes
    Display*		/* display */,
    int			/* screen_number */,
    _Xconst char*	/* user_geometry */,
    _Xconst char*	/* default_geometry */,
    unsigned int	/* border_width */,
    XSizeHints*		/* hints */,
    int*		/* x_return */,
    int*		/* y_return */,
    int*		/* width_return */,
    int*		/* height_return */,
    int*		/* gravity_return */
#endif
);

extern void XXorRegion(
#if NeedFunctionPrototypes
    Region		/* sra */,
    Region		/* srb */,
    Region		/* dr_return */
#endif
);

_XFUNCPROTOEND

#if defined(MAC_OSX_TK)
#   undef Region
#endif

#endif /* _XUTIL_H_ */
/* $XConsortium: cursorfont.h,v 1.2 88/09/06 16:44:27 jim Exp $ */
#define XC_num_glyphs 154
#define XC_X_cursor 0
#define XC_arrow 2
#define XC_based_arrow_down 4
#define XC_based_arrow_up 6
#define XC_boat 8
#define XC_bogosity 10
#define XC_bottom_left_corner 12
#define XC_bottom_right_corner 14
#define XC_bottom_side 16
#define XC_bottom_tee 18
#define XC_box_spiral 20
#define XC_center_ptr 22
#define XC_circle 24
#define XC_clock 26
#define XC_coffee_mug 28
#define XC_cross 30
#define XC_cross_reverse 32
#define XC_crosshair 34
#define XC_diamond_cross 36
#define XC_dot 38
#define XC_dotbox 40
#define XC_double_arrow 42
#define XC_draft_large 44
#define XC_draft_small 46
#define XC_draped_box 48
#define XC_exchange 50
#define XC_fleur 52
#define XC_gobbler 54
#define XC_gumby 56
#define XC_hand1 58
#define XC_hand2 60
#define XC_heart 62
#define XC_icon 64
#define XC_iron_cross 66
#define XC_left_ptr 68
#define XC_left_side 70
#define XC_left_tee 72
#define XC_leftbutton 74
#define XC_ll_angle 76
#define XC_lr_angle 78
#define XC_man 80
#define XC_middlebutton 82
#define XC_mouse 84
#define XC_pencil 86
#define XC_pirate 88
#define XC_plus 90
#define XC_question_arrow 92
#define XC_right_ptr 94
#define XC_right_side 96
#define XC_right_tee 98
#define XC_rightbutton 100
#define XC_rtl_logo 102
#define XC_sailboat 104
#define XC_sb_down_arrow 106
#define XC_sb_h_double_arrow 108
#define XC_sb_left_arrow 110
#define XC_sb_right_arrow 112
#define XC_sb_up_arrow 114
#define XC_sb_v_double_arrow 116
#define XC_shuttle 118
#define XC_sizing 120
#define XC_spider 122
#define XC_spraycan 124
#define XC_star 126
#define XC_target 128
#define XC_tcross 130
#define XC_top_left_arrow 132
#define XC_top_left_corner 134
#define XC_top_right_corner 136
#define XC_top_side 138
#define XC_top_tee 140
#define XC_trek 142
#define XC_ul_angle 144
#define XC_umbrella 146
#define XC_ur_angle 148
#define XC_watch 150
#define XC_xterm 152
/* $XConsortium: keysym.h,v 1.13 91/03/13 20:09:49 rws Exp $ */

/***********************************************************
Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts,
and the Massachusetts Institute of Technology, Cambridge, Massachusetts.

                        All Rights Reserved

Permission to use, copy, modify, and distribute this software and its 
documentation for any purpose and without fee is hereby granted, 
provided that the above copyright notice appear in all copies and that
both that copyright notice and this permission notice appear in 
supporting documentation, and that the names of Digital or MIT not be
used in advertising or publicity pertaining to distribution of the
software without specific, written prior permission.  

DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL
DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR
ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
SOFTWARE.

******************************************************************/

/* default keysyms */
#define XK_MISCELLANY
#define XK_LATIN1
#define XK_LATIN2
#define XK_LATIN3
#define XK_LATIN4
#define XK_GREEK

#include <X11/keysymdef.h>
/* $XConsortium: keysymdef.h,v 1.15 93/04/02 10:57:36 rws Exp $ */

/***********************************************************
Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts,
and the Massachusetts Institute of Technology, Cambridge, Massachusetts.

                        All Rights Reserved

Permission to use, copy, modify, and distribute this software and its
documentation for any purpose and without fee is hereby granted,
provided that the above copyright notice appear in all copies and that
both that copyright notice and this permission notice appear in
supporting documentation, and that the names of Digital or MIT not be
used in advertising or publicity pertaining to distribution of the
software without specific, written prior permission.

DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL
DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR
ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
SOFTWARE.

******************************************************************/

#define XK_VoidSymbol		0xFFFFFF	/* void symbol */

#ifdef XK_MISCELLANY
/*
 * TTY Functions, cleverly chosen to map to ascii, for convenience of
 * programming, but could have been arbitrary (at the cost of lookup
 * tables in client code.
 */

#define XK_BackSpace		0xFF08	/* back space, back char */
#define XK_Tab			0xFF09
#define XK_Linefeed		0xFF0A	/* Linefeed, LF */
#define XK_Clear		0xFF0B
#define XK_Return		0xFF0D	/* Return, enter */
#define XK_Pause		0xFF13	/* Pause, hold */
#define XK_Scroll_Lock		0xFF14
#define XK_Sys_Req		0xFF15
#define XK_Escape		0xFF1B
#define XK_Delete		0xFFFF	/* Delete, rubout */



/* International & multi-key character composition */

#define XK_Multi_key		0xFF20  /* Multi-key character compose */

/* Japanese keyboard support */

#define XK_Kanji		0xFF21	/* Kanji, Kanji convert */
#define XK_Muhenkan		0xFF22  /* Cancel Conversion */
#define XK_Henkan_Mode		0xFF23  /* Start/Stop Conversion */
#define XK_Henkan		0xFF23  /* Alias for Henkan_Mode */
#define XK_Romaji		0xFF24  /* to Romaji */
#define XK_Hiragana		0xFF25  /* to Hiragana */
#define XK_Katakana		0xFF26  /* to Katakana */
#define XK_Hiragana_Katakana	0xFF27  /* Hiragana/Katakana toggle */
#define XK_Zenkaku		0xFF28  /* to Zenkaku */
#define XK_Hankaku		0xFF29  /* to Hankaku */
#define XK_Zenkaku_Hankaku	0xFF2A  /* Zenkaku/Hankaku toggle */
#define XK_Touroku		0xFF2B  /* Add to Dictionary */
#define XK_Massyo		0xFF2C  /* Delete from Dictionary */
#define XK_Kana_Lock		0xFF2D  /* Kana Lock */
#define XK_Kana_Shift		0xFF2E  /* Kana Shift */
#define XK_Eisu_Shift		0xFF2F  /* Alphanumeric Shift */
#define XK_Eisu_toggle		0xFF30  /* Alphanumeric toggle */

/* Cursor control & motion */

#define XK_Home			0xFF50
#define XK_Left			0xFF51	/* Move left, left arrow */
#define XK_Up			0xFF52	/* Move up, up arrow */
#define XK_Right		0xFF53	/* Move right, right arrow */
#define XK_Down			0xFF54	/* Move down, down arrow */
#define XK_Prior		0xFF55	/* Prior, previous */
#define XK_Page_Up		0xFF55
#define XK_Next			0xFF56	/* Next */
#define XK_Page_Down		0xFF56
#define XK_End			0xFF57	/* EOL */
#define XK_Begin		0xFF58	/* BOL */

/* Special Windows keyboard keys */

#define XK_Win_L		0xFF5B	/* Left-hand Windows */
#define XK_Win_R		0xFF5C	/* Right-hand Windows */
#define XK_App			0xFF5D	/* Menu key */

/* Misc Functions */

#define XK_Select		0xFF60	/* Select, mark */
#define XK_Print		0xFF61
#define XK_Execute		0xFF62	/* Execute, run, do */
#define XK_Insert		0xFF63	/* Insert, insert here */
#define XK_Undo			0xFF65	/* Undo, oops */
#define XK_Redo			0xFF66	/* redo, again */
#define XK_Menu			0xFF67
#define XK_Find			0xFF68	/* Find, search */
#define XK_Cancel		0xFF69	/* Cancel, stop, abort, exit */
#define XK_Help			0xFF6A	/* Help, ? */
#define XK_Break		0xFF6B
#define XK_Mode_switch		0xFF7E	/* Character set switch */
#define XK_script_switch        0xFF7E  /* Alias for mode_switch */
#define XK_Num_Lock		0xFF7F

/* Keypad Functions, keypad numbers cleverly chosen to map to ascii */

#define XK_KP_Space		0xFF80	/* space */
#define XK_KP_Tab		0xFF89
#define XK_KP_Enter		0xFF8D	/* enter */
#define XK_KP_F1		0xFF91	/* PF1, KP_A, ... */
#define XK_KP_F2		0xFF92
#define XK_KP_F3		0xFF93
#define XK_KP_F4		0xFF94
#define XK_KP_Home		0xFF95
#define XK_KP_Left		0xFF96
#define XK_KP_Up		0xFF97
#define XK_KP_Right		0xFF98
#define XK_KP_Down		0xFF99
#define XK_KP_Prior		0xFF9A
#define XK_KP_Page_Up		0xFF9A
#define XK_KP_Next		0xFF9B
#define XK_KP_Page_Down		0xFF9B
#define XK_KP_End		0xFF9C
#define XK_KP_Begin		0xFF9D
#define XK_KP_Insert		0xFF9E
#define XK_KP_Delete		0xFF9F
#define XK_KP_Equal		0xFFBD	/* equals */
#define XK_KP_Multiply		0xFFAA
#define XK_KP_Add		0xFFAB
#define XK_KP_Separator		0xFFAC	/* separator, often comma */
#define XK_KP_Subtract		0xFFAD
#define XK_KP_Decimal		0xFFAE
#define XK_KP_Divide		0xFFAF

#define XK_KP_0			0xFFB0
#define XK_KP_1			0xFFB1
#define XK_KP_2			0xFFB2
#define XK_KP_3			0xFFB3
#define XK_KP_4			0xFFB4
#define XK_KP_5			0xFFB5
#define XK_KP_6			0xFFB6
#define XK_KP_7			0xFFB7
#define XK_KP_8			0xFFB8
#define XK_KP_9			0xFFB9



/*
 * Auxilliary Functions; note the duplicate definitions for left and right
 * function keys;  Sun keyboards and a few other manufactures have such
 * function key groups on the left and/or right sides of the keyboard.
 * We've not found a keyboard with more than 35 function keys total.
 */

#define XK_F1			0xFFBE
#define XK_F2			0xFFBF
#define XK_F3			0xFFC0
#define XK_F4			0xFFC1
#define XK_F5			0xFFC2
#define XK_F6			0xFFC3
#define XK_F7			0xFFC4
#define XK_F8			0xFFC5
#define XK_F9			0xFFC6
#define XK_F10			0xFFC7
#define XK_F11			0xFFC8
#define XK_L1			0xFFC8
#define XK_F12			0xFFC9
#define XK_L2			0xFFC9
#define XK_F13			0xFFCA
#define XK_L3			0xFFCA
#define XK_F14			0xFFCB
#define XK_L4			0xFFCB
#define XK_F15			0xFFCC
#define XK_L5			0xFFCC
#define XK_F16			0xFFCD
#define XK_L6			0xFFCD
#define XK_F17			0xFFCE
#define XK_L7			0xFFCE
#define XK_F18			0xFFCF
#define XK_L8			0xFFCF
#define XK_F19			0xFFD0
#define XK_L9			0xFFD0
#define XK_F20			0xFFD1
#define XK_L10			0xFFD1
#define XK_F21			0xFFD2
#define XK_R1			0xFFD2
#define XK_F22			0xFFD3
#define XK_R2			0xFFD3
#define XK_F23			0xFFD4
#define XK_R3			0xFFD4
#define XK_F24			0xFFD5
#define XK_R4			0xFFD5
#define XK_F25			0xFFD6
#define XK_R5			0xFFD6
#define XK_F26			0xFFD7
#define XK_R6			0xFFD7
#define XK_F27			0xFFD8
#define XK_R7			0xFFD8
#define XK_F28			0xFFD9
#define XK_R8			0xFFD9
#define XK_F29			0xFFDA
#define XK_R9			0xFFDA
#define XK_F30			0xFFDB
#define XK_R10			0xFFDB
#define XK_F31			0xFFDC
#define XK_R11			0xFFDC
#define XK_F32			0xFFDD
#define XK_R12			0xFFDD
#define XK_F33			0xFFDE
#define XK_R13			0xFFDE
#define XK_F34			0xFFDF
#define XK_R14			0xFFDF
#define XK_F35			0xFFE0
#define XK_R15			0xFFE0

/* Modifiers */

#define XK_Shift_L		0xFFE1	/* Left shift */
#define XK_Shift_R		0xFFE2	/* Right shift */
#define XK_Control_L		0xFFE3	/* Left control */
#define XK_Control_R		0xFFE4	/* Right control */
#define XK_Caps_Lock		0xFFE5	/* Caps lock */
#define XK_Shift_Lock		0xFFE6	/* Shift lock */

#define XK_Meta_L		0xFFE7	/* Left meta */
#define XK_Meta_R		0xFFE8	/* Right meta */
#define XK_Alt_L		0xFFE9	/* Left alt */
#define XK_Alt_R		0xFFEA	/* Right alt */
#define XK_Super_L		0xFFEB	/* Left super */
#define XK_Super_R		0xFFEC	/* Right super */
#define XK_Hyper_L		0xFFED	/* Left hyper */
#define XK_Hyper_R		0xFFEE	/* Right hyper */
#endif /* XK_MISCELLANY */

/*
 *  Latin 1
 *  Byte 3 = 0
 */
#ifdef XK_LATIN1
#define XK_space               0x020
#define XK_exclam              0x021
#define XK_quotedbl            0x022
#define XK_numbersign          0x023
#define XK_dollar              0x024
#define XK_percent             0x025
#define XK_ampersand           0x026
#define XK_apostrophe          0x027
#define XK_quoteright          0x027	/* deprecated */
#define XK_parenleft           0x028
#define XK_parenright          0x029
#define XK_asterisk            0x02a
#define XK_plus                0x02b
#define XK_comma               0x02c
#define XK_minus               0x02d
#define XK_period              0x02e
#define XK_slash               0x02f
#define XK_0                   0x030
#define XK_1                   0x031
#define XK_2                   0x032
#define XK_3                   0x033
#define XK_4                   0x034
#define XK_5                   0x035
#define XK_6                   0x036
#define XK_7                   0x037
#define XK_8                   0x038
#define XK_9                   0x039
#define XK_colon               0x03a
#define XK_semicolon           0x03b
#define XK_less                0x03c
#define XK_equal               0x03d
#define XK_greater             0x03e
#define XK_question            0x03f
#define XK_at                  0x040
#define XK_A                   0x041
#define XK_B                   0x042
#define XK_C                   0x043
#define XK_D                   0x044
#define XK_E                   0x045
#define XK_F                   0x046
#define XK_G                   0x047
#define XK_H                   0x048
#define XK_I                   0x049
#define XK_J                   0x04a
#define XK_K                   0x04b
#define XK_L                   0x04c
#define XK_M                   0x04d
#define XK_N                   0x04e
#define XK_O                   0x04f
#define XK_P                   0x050
#define XK_Q                   0x051
#define XK_R                   0x052
#define XK_S                   0x053
#define XK_T                   0x054
#define XK_U                   0x055
#define XK_V                   0x056
#define XK_W                   0x057
#define XK_X                   0x058
#define XK_Y                   0x059
#define XK_Z                   0x05a
#define XK_bracketleft         0x05b
#define XK_backslash           0x05c
#define XK_bracketright        0x05d
#define XK_asciicircum         0x05e
#define XK_underscore          0x05f
#define XK_grave               0x060
#define XK_quoteleft           0x060	/* deprecated */
#define XK_a                   0x061
#define XK_b                   0x062
#define XK_c                   0x063
#define XK_d                   0x064
#define XK_e                   0x065
#define XK_f                   0x066
#define XK_g                   0x067
#define XK_h                   0x068
#define XK_i                   0x069
#define XK_j                   0x06a
#define XK_k                   0x06b
#define XK_l                   0x06c
#define XK_m                   0x06d
#define XK_n                   0x06e
#define XK_o                   0x06f
#define XK_p                   0x070
#define XK_q                   0x071
#define XK_r                   0x072
#define XK_s                   0x073
#define XK_t                   0x074
#define XK_u                   0x075
#define XK_v                   0x076
#define XK_w                   0x077
#define XK_x                   0x078
#define XK_y                   0x079
#define XK_z                   0x07a
#define XK_braceleft           0x07b
#define XK_bar                 0x07c
#define XK_braceright          0x07d
#define XK_asciitilde          0x07e

#define XK_nobreakspace        0x0a0
#define XK_exclamdown          0x0a1
#define XK_cent        	       0x0a2
#define XK_sterling            0x0a3
#define XK_currency            0x0a4
#define XK_yen                 0x0a5
#define XK_brokenbar           0x0a6
#define XK_section             0x0a7
#define XK_diaeresis           0x0a8
#define XK_copyright           0x0a9
#define XK_ordfeminine         0x0aa
#define XK_guillemotleft       0x0ab	/* left angle quotation mark */
#define XK_notsign             0x0ac
#define XK_hyphen              0x0ad
#define XK_registered          0x0ae
#define XK_macron              0x0af
#define XK_degree              0x0b0
#define XK_plusminus           0x0b1
#define XK_twosuperior         0x0b2
#define XK_threesuperior       0x0b3
#define XK_acute               0x0b4
#define XK_mu                  0x0b5
#define XK_paragraph           0x0b6
#define XK_periodcentered      0x0b7
#define XK_cedilla             0x0b8
#define XK_onesuperior         0x0b9
#define XK_masculine           0x0ba
#define XK_guillemotright      0x0bb	/* right angle quotation mark */
#define XK_onequarter          0x0bc
#define XK_onehalf             0x0bd
#define XK_threequarters       0x0be
#define XK_questiondown        0x0bf
#define XK_Agrave              0x0c0
#define XK_Aacute              0x0c1
#define XK_Acircumflex         0x0c2
#define XK_Atilde              0x0c3
#define XK_Adiaeresis          0x0c4
#define XK_Aring               0x0c5
#define XK_AE                  0x0c6
#define XK_Ccedilla            0x0c7
#define XK_Egrave              0x0c8
#define XK_Eacute              0x0c9
#define XK_Ecircumflex         0x0ca
#define XK_Ediaeresis          0x0cb
#define XK_Igrave              0x0cc
#define XK_Iacute              0x0cd
#define XK_Icircumflex         0x0ce
#define XK_Idiaeresis          0x0cf
#define XK_ETH                 0x0d0
#define XK_Eth                 0x0d0	/* deprecated */
#define XK_Ntilde              0x0d1
#define XK_Ograve              0x0d2
#define XK_Oacute              0x0d3
#define XK_Ocircumflex         0x0d4
#define XK_Otilde              0x0d5
#define XK_Odiaeresis          0x0d6
#define XK_multiply            0x0d7
#define XK_Ooblique            0x0d8
#define XK_Ugrave              0x0d9
#define XK_Uacute              0x0da
#define XK_Ucircumflex         0x0db
#define XK_Udiaeresis          0x0dc
#define XK_Yacute              0x0dd
#define XK_THORN               0x0de
#define XK_Thorn               0x0de	/* deprecated */
#define XK_ssharp              0x0df
#define XK_agrave              0x0e0
#define XK_aacute              0x0e1
#define XK_acircumflex         0x0e2
#define XK_atilde              0x0e3
#define XK_adiaeresis          0x0e4
#define XK_aring               0x0e5
#define XK_ae                  0x0e6
#define XK_ccedilla            0x0e7
#define XK_egrave              0x0e8
#define XK_eacute              0x0e9
#define XK_ecircumflex         0x0ea
#define XK_ediaeresis          0x0eb
#define XK_igrave              0x0ec
#define XK_iacute              0x0ed
#define XK_icircumflex         0x0ee
#define XK_idiaeresis          0x0ef
#define XK_eth                 0x0f0
#define XK_ntilde              0x0f1
#define XK_ograve              0x0f2
#define XK_oacute              0x0f3
#define XK_ocircumflex         0x0f4
#define XK_otilde              0x0f5
#define XK_odiaeresis          0x0f6
#define XK_division            0x0f7
#define XK_oslash              0x0f8
#define XK_ugrave              0x0f9
#define XK_uacute              0x0fa
#define XK_ucircumflex         0x0fb
#define XK_udiaeresis          0x0fc
#define XK_yacute              0x0fd
#define XK_thorn               0x0fe
#define XK_ydiaeresis          0x0ff
#endif /* XK_LATIN1 */

/*
 *   Latin 2
 *   Byte 3 = 1
 */

#ifdef XK_LATIN2
#define XK_Aogonek             0x1a1
#define XK_breve               0x1a2
#define XK_Lstroke             0x1a3
#define XK_Lcaron              0x1a5
#define XK_Sacute              0x1a6
#define XK_Scaron              0x1a9
#define XK_Scedilla            0x1aa
#define XK_Tcaron              0x1ab
#define XK_Zacute              0x1ac
#define XK_Zcaron              0x1ae
#define XK_Zabovedot           0x1af
#define XK_aogonek             0x1b1
#define XK_ogonek              0x1b2
#define XK_lstroke             0x1b3
#define XK_lcaron              0x1b5
#define XK_sacute              0x1b6
#define XK_caron               0x1b7
#define XK_scaron              0x1b9
#define XK_scedilla            0x1ba
#define XK_tcaron              0x1bb
#define XK_zacute              0x1bc
#define XK_doubleacute         0x1bd
#define XK_zcaron              0x1be
#define XK_zabovedot           0x1bf
#define XK_Racute              0x1c0
#define XK_Abreve              0x1c3
#define XK_Lacute              0x1c5
#define XK_Cacute              0x1c6
#define XK_Ccaron              0x1c8
#define XK_Eogonek             0x1ca
#define XK_Ecaron              0x1cc
#define XK_Dcaron              0x1cf
#define XK_Dstroke             0x1d0
#define XK_Nacute              0x1d1
#define XK_Ncaron              0x1d2
#define XK_Odoubleacute        0x1d5
#define XK_Rcaron              0x1d8
#define XK_Uring               0x1d9
#define XK_Udoubleacute        0x1db
#define XK_Tcedilla            0x1de
#define XK_racute              0x1e0
#define XK_abreve              0x1e3
#define XK_lacute              0x1e5
#define XK_cacute              0x1e6
#define XK_ccaron              0x1e8
#define XK_eogonek             0x1ea
#define XK_ecaron              0x1ec
#define XK_dcaron              0x1ef
#define XK_dstroke             0x1f0
#define XK_nacute              0x1f1
#define XK_ncaron              0x1f2
#define XK_odoubleacute        0x1f5
#define XK_udoubleacute        0x1fb
#define XK_rcaron              0x1f8
#define XK_uring               0x1f9
#define XK_tcedilla            0x1fe
#define XK_abovedot            0x1ff
#endif /* XK_LATIN2 */

/*
 *   Latin 3
 *   Byte 3 = 2
 */

#ifdef XK_LATIN3
#define XK_Hstroke             0x2a1
#define XK_Hcircumflex         0x2a6
#define XK_Iabovedot           0x2a9
#define XK_Gbreve              0x2ab
#define XK_Jcircumflex         0x2ac
#define XK_hstroke             0x2b1
#define XK_hcircumflex         0x2b6
#define XK_idotless            0x2b9
#define XK_gbreve              0x2bb
#define XK_jcircumflex         0x2bc
#define XK_Cabovedot           0x2c5
#define XK_Ccircumflex         0x2c6
#define XK_Gabovedot           0x2d5
#define XK_Gcircumflex         0x2d8
#define XK_Ubreve              0x2dd
#define XK_Scircumflex         0x2de
#define XK_cabovedot           0x2e5
#define XK_ccircumflex         0x2e6
#define XK_gabovedot           0x2f5
#define XK_gcircumflex         0x2f8
#define XK_ubreve              0x2fd
#define XK_scircumflex         0x2fe
#endif /* XK_LATIN3 */


/*
 *   Latin 4
 *   Byte 3 = 3
 */

#ifdef XK_LATIN4
#define XK_kra                 0x3a2
#define XK_kappa               0x3a2	/* deprecated */
#define XK_Rcedilla            0x3a3
#define XK_Itilde              0x3a5
#define XK_Lcedilla            0x3a6
#define XK_Emacron             0x3aa
#define XK_Gcedilla            0x3ab
#define XK_Tslash              0x3ac
#define XK_rcedilla            0x3b3
#define XK_itilde              0x3b5
#define XK_lcedilla            0x3b6
#define XK_emacron             0x3ba
#define XK_gcedilla            0x3bb
#define XK_tslash              0x3bc
#define XK_ENG                 0x3bd
#define XK_eng                 0x3bf
#define XK_Amacron             0x3c0
#define XK_Iogonek             0x3c7
#define XK_Eabovedot           0x3cc
#define XK_Imacron             0x3cf
#define XK_Ncedilla            0x3d1
#define XK_Omacron             0x3d2
#define XK_Kcedilla            0x3d3
#define XK_Uogonek             0x3d9
#define XK_Utilde              0x3dd
#define XK_Umacron             0x3de
#define XK_amacron             0x3e0
#define XK_iogonek             0x3e7
#define XK_eabovedot           0x3ec
#define XK_imacron             0x3ef
#define XK_ncedilla            0x3f1
#define XK_omacron             0x3f2
#define XK_kcedilla            0x3f3
#define XK_uogonek             0x3f9
#define XK_utilde              0x3fd
#define XK_umacron             0x3fe
#endif /* XK_LATIN4 */

/*
 * Katakana
 * Byte 3 = 4
 */

#ifdef XK_KATAKANA
#define XK_overline				       0x47e
#define XK_kana_fullstop                               0x4a1
#define XK_kana_openingbracket                         0x4a2
#define XK_kana_closingbracket                         0x4a3
#define XK_kana_comma                                  0x4a4
#define XK_kana_conjunctive                            0x4a5
#define XK_kana_middledot                              0x4a5  /* deprecated */
#define XK_kana_WO                                     0x4a6
#define XK_kana_a                                      0x4a7
#define XK_kana_i                                      0x4a8
#define XK_kana_u                                      0x4a9
#define XK_kana_e                                      0x4aa
#define XK_kana_o                                      0x4ab
#define XK_kana_ya                                     0x4ac
#define XK_kana_yu                                     0x4ad
#define XK_kana_yo                                     0x4ae
#define XK_kana_tsu                                    0x4af
#define XK_kana_tu                                     0x4af  /* deprecated */
#define XK_prolongedsound                              0x4b0
#define XK_kana_A                                      0x4b1
#define XK_kana_I                                      0x4b2
#define XK_kana_U                                      0x4b3
#define XK_kana_E                                      0x4b4
#define XK_kana_O                                      0x4b5
#define XK_kana_KA                                     0x4b6
#define XK_kana_KI                                     0x4b7
#define XK_kana_KU                                     0x4b8
#define XK_kana_KE                                     0x4b9
#define XK_kana_KO                                     0x4ba
#define XK_kana_SA                                     0x4bb
#define XK_kana_SHI                                    0x4bc
#define XK_kana_SU                                     0x4bd
#define XK_kana_SE                                     0x4be
#define XK_kana_SO                                     0x4bf
#define XK_kana_TA                                     0x4c0
#define XK_kana_CHI                                    0x4c1
#define XK_kana_TI                                     0x4c1  /* deprecated */
#define XK_kana_TSU                                    0x4c2
#define XK_kana_TU                                     0x4c2  /* deprecated */
#define XK_kana_TE                                     0x4c3
#define XK_kana_TO                                     0x4c4
#define XK_kana_NA                                     0x4c5
#define XK_kana_NI                                     0x4c6
#define XK_kana_NU                                     0x4c7
#define XK_kana_NE                                     0x4c8
#define XK_kana_NO                                     0x4c9
#define XK_kana_HA                                     0x4ca
#define XK_kana_HI                                     0x4cb
#define XK_kana_FU                                     0x4cc
#define XK_kana_HU                                     0x4cc  /* deprecated */
#define XK_kana_HE                                     0x4cd
#define XK_kana_HO                                     0x4ce
#define XK_kana_MA                                     0x4cf
#define XK_kana_MI                                     0x4d0
#define XK_kana_MU                                     0x4d1
#define XK_kana_ME                                     0x4d2
#define XK_kana_MO                                     0x4d3
#define XK_kana_YA                                     0x4d4
#define XK_kana_YU                                     0x4d5
#define XK_kana_YO                                     0x4d6
#define XK_kana_RA                                     0x4d7
#define XK_kana_RI                                     0x4d8
#define XK_kana_RU                                     0x4d9
#define XK_kana_RE                                     0x4da
#define XK_kana_RO                                     0x4db
#define XK_kana_WA                                     0x4dc
#define XK_kana_N                                      0x4dd
#define XK_voicedsound                                 0x4de
#define XK_semivoicedsound                             0x4df
#define XK_kana_switch          0xFF7E  /* Alias for mode_switch */
#endif /* XK_KATAKANA */

/*
 *  Arabic
 *  Byte 3 = 5
 */

#ifdef XK_ARABIC
#define XK_Arabic_comma                                0x5ac
#define XK_Arabic_semicolon                            0x5bb
#define XK_Arabic_question_mark                        0x5bf
#define XK_Arabic_hamza                                0x5c1
#define XK_Arabic_maddaonalef                          0x5c2
#define XK_Arabic_hamzaonalef                          0x5c3
#define XK_Arabic_hamzaonwaw                           0x5c4
#define XK_Arabic_hamzaunderalef                       0x5c5
#define XK_Arabic_hamzaonyeh                           0x5c6
#define XK_Arabic_alef                                 0x5c7
#define XK_Arabic_beh                                  0x5c8
#define XK_Arabic_tehmarbuta                           0x5c9
#define XK_Arabic_teh                                  0x5ca
#define XK_Arabic_theh                                 0x5cb
#define XK_Arabic_jeem                                 0x5cc
#define XK_Arabic_hah                                  0x5cd
#define XK_Arabic_khah                                 0x5ce
#define XK_Arabic_dal                                  0x5cf
#define XK_Arabic_thal                                 0x5d0
#define XK_Arabic_ra                                   0x5d1
#define XK_Arabic_zain                                 0x5d2
#define XK_Arabic_seen                                 0x5d3
#define XK_Arabic_sheen                                0x5d4
#define XK_Arabic_sad                                  0x5d5
#define XK_Arabic_dad                                  0x5d6
#define XK_Arabic_tah                                  0x5d7
#define XK_Arabic_zah                                  0x5d8
#define XK_Arabic_ain                                  0x5d9
#define XK_Arabic_ghain                                0x5da
#define XK_Arabic_tatweel                              0x5e0
#define XK_Arabic_feh                                  0x5e1
#define XK_Arabic_qaf                                  0x5e2
#define XK_Arabic_kaf                                  0x5e3
#define XK_Arabic_lam                                  0x5e4
#define XK_Arabic_meem                                 0x5e5
#define XK_Arabic_noon                                 0x5e6
#define XK_Arabic_ha                                   0x5e7
#define XK_Arabic_heh                                  0x5e7  /* deprecated */
#define XK_Arabic_waw                                  0x5e8
#define XK_Arabic_alefmaksura                          0x5e9
#define XK_Arabic_yeh                                  0x5ea
#define XK_Arabic_fathatan                             0x5eb
#define XK_Arabic_dammatan                             0x5ec
#define XK_Arabic_kasratan                             0x5ed
#define XK_Arabic_fatha                                0x5ee
#define XK_Arabic_damma                                0x5ef
#define XK_Arabic_kasra                                0x5f0
#define XK_Arabic_shadda                               0x5f1
#define XK_Arabic_sukun                                0x5f2
#define XK_Arabic_switch        0xFF7E  /* Alias for mode_switch */
#endif /* XK_ARABIC */

/*
 * Cyrillic
 * Byte 3 = 6
 */
#ifdef XK_CYRILLIC
#define XK_Serbian_dje                                 0x6a1
#define XK_Macedonia_gje                               0x6a2
#define XK_Cyrillic_io                                 0x6a3
#define XK_Ukrainian_ie                                0x6a4
#define XK_Ukranian_je                                 0x6a4  /* deprecated */
#define XK_Macedonia_dse                               0x6a5
#define XK_Ukrainian_i                                 0x6a6
#define XK_Ukranian_i                                  0x6a6  /* deprecated */
#define XK_Ukrainian_yi                                0x6a7
#define XK_Ukranian_yi                                 0x6a7  /* deprecated */
#define XK_Cyrillic_je                                 0x6a8
#define XK_Serbian_je                                  0x6a8  /* deprecated */
#define XK_Cyrillic_lje                                0x6a9
#define XK_Serbian_lje                                 0x6a9  /* deprecated */
#define XK_Cyrillic_nje                                0x6aa
#define XK_Serbian_nje                                 0x6aa  /* deprecated */
#define XK_Serbian_tshe                                0x6ab
#define XK_Macedonia_kje                               0x6ac
#define XK_Byelorussian_shortu                         0x6ae
#define XK_Cyrillic_dzhe                               0x6af
#define XK_Serbian_dze                                 0x6af  /* deprecated */
#define XK_numerosign                                  0x6b0
#define XK_Serbian_DJE                                 0x6b1
#define XK_Macedonia_GJE                               0x6b2
#define XK_Cyrillic_IO                                 0x6b3
#define XK_Ukrainian_IE                                0x6b4
#define XK_Ukranian_JE                                 0x6b4  /* deprecated */
#define XK_Macedonia_DSE                               0x6b5
#define XK_Ukrainian_I                                 0x6b6
#define XK_Ukranian_I                                  0x6b6  /* deprecated */
#define XK_Ukrainian_YI                                0x6b7
#define XK_Ukranian_YI                                 0x6b7  /* deprecated */
#define XK_Cyrillic_JE                                 0x6b8
#define XK_Serbian_JE                                  0x6b8  /* deprecated */
#define XK_Cyrillic_LJE                                0x6b9
#define XK_Serbian_LJE                                 0x6b9  /* deprecated */
#define XK_Cyrillic_NJE                                0x6ba
#define XK_Serbian_NJE                                 0x6ba  /* deprecated */
#define XK_Serbian_TSHE                                0x6bb
#define XK_Macedonia_KJE                               0x6bc
#define XK_Byelorussian_SHORTU                         0x6be
#define XK_Cyrillic_DZHE                               0x6bf
#define XK_Serbian_DZE                                 0x6bf  /* deprecated */
#define XK_Cyrillic_yu                                 0x6c0
#define XK_Cyrillic_a                                  0x6c1
#define XK_Cyrillic_be                                 0x6c2
#define XK_Cyrillic_tse                                0x6c3
#define XK_Cyrillic_de                                 0x6c4
#define XK_Cyrillic_ie                                 0x6c5
#define XK_Cyrillic_ef                                 0x6c6
#define XK_Cyrillic_ghe                                0x6c7
#define XK_Cyrillic_ha                                 0x6c8
#define XK_Cyrillic_i                                  0x6c9
#define XK_Cyrillic_shorti                             0x6ca
#define XK_Cyrillic_ka                                 0x6cb
#define XK_Cyrillic_el                                 0x6cc
#define XK_Cyrillic_em                                 0x6cd
#define XK_Cyrillic_en                                 0x6ce
#define XK_Cyrillic_o                                  0x6cf
#define XK_Cyrillic_pe                                 0x6d0
#define XK_Cyrillic_ya                                 0x6d1
#define XK_Cyrillic_er                                 0x6d2
#define XK_Cyrillic_es                                 0x6d3
#define XK_Cyrillic_te                                 0x6d4
#define XK_Cyrillic_u                                  0x6d5
#define XK_Cyrillic_zhe                                0x6d6
#define XK_Cyrillic_ve                                 0x6d7
#define XK_Cyrillic_softsign                           0x6d8
#define XK_Cyrillic_yeru                               0x6d9
#define XK_Cyrillic_ze                                 0x6da
#define XK_Cyrillic_sha                                0x6db
#define XK_Cyrillic_e                                  0x6dc
#define XK_Cyrillic_shcha                              0x6dd
#define XK_Cyrillic_che                                0x6de
#define XK_Cyrillic_hardsign                           0x6df
#define XK_Cyrillic_YU                                 0x6e0
#define XK_Cyrillic_A                                  0x6e1
#define XK_Cyrillic_BE                                 0x6e2
#define XK_Cyrillic_TSE                                0x6e3
#define XK_Cyrillic_DE                                 0x6e4
#define XK_Cyrillic_IE                                 0x6e5
#define XK_Cyrillic_EF                                 0x6e6
#define XK_Cyrillic_GHE                                0x6e7
#define XK_Cyrillic_HA                                 0x6e8
#define XK_Cyrillic_I                                  0x6e9
#define XK_Cyrillic_SHORTI                             0x6ea
#define XK_Cyrillic_KA                                 0x6eb
#define XK_Cyrillic_EL                                 0x6ec
#define XK_Cyrillic_EM                                 0x6ed
#define XK_Cyrillic_EN                                 0x6ee
#define XK_Cyrillic_O                                  0x6ef
#define XK_Cyrillic_PE                                 0x6f0
#define XK_Cyrillic_YA                                 0x6f1
#define XK_Cyrillic_ER                                 0x6f2
#define XK_Cyrillic_ES                                 0x6f3
#define XK_Cyrillic_TE                                 0x6f4
#define XK_Cyrillic_U                                  0x6f5
#define XK_Cyrillic_ZHE                                0x6f6
#define XK_Cyrillic_VE                                 0x6f7
#define XK_Cyrillic_SOFTSIGN                           0x6f8
#define XK_Cyrillic_YERU                               0x6f9
#define XK_Cyrillic_ZE                                 0x6fa
#define XK_Cyrillic_SHA                                0x6fb
#define XK_Cyrillic_E                                  0x6fc
#define XK_Cyrillic_SHCHA                              0x6fd
#define XK_Cyrillic_CHE                                0x6fe
#define XK_Cyrillic_HARDSIGN                           0x6ff
#endif /* XK_CYRILLIC */

/*
 * Greek
 * Byte 3 = 7
 */

#ifdef XK_GREEK
#define XK_Greek_ALPHAaccent                           0x7a1
#define XK_Greek_EPSILONaccent                         0x7a2
#define XK_Greek_ETAaccent                             0x7a3
#define XK_Greek_IOTAaccent                            0x7a4
#define XK_Greek_IOTAdiaeresis                         0x7a5
#define XK_Greek_OMICRONaccent                         0x7a7
#define XK_Greek_UPSILONaccent                         0x7a8
#define XK_Greek_UPSILONdieresis                       0x7a9
#define XK_Greek_OMEGAaccent                           0x7ab
#define XK_Greek_accentdieresis                        0x7ae
#define XK_Greek_horizbar                              0x7af
#define XK_Greek_alphaaccent                           0x7b1
#define XK_Greek_epsilonaccent                         0x7b2
#define XK_Greek_etaaccent                             0x7b3
#define XK_Greek_iotaaccent                            0x7b4
#define XK_Greek_iotadieresis                          0x7b5
#define XK_Greek_iotaaccentdieresis                    0x7b6
#define XK_Greek_omicronaccent                         0x7b7
#define XK_Greek_upsilonaccent                         0x7b8
#define XK_Greek_upsilondieresis                       0x7b9
#define XK_Greek_upsilonaccentdieresis                 0x7ba
#define XK_Greek_omegaaccent                           0x7bb
#define XK_Greek_ALPHA                                 0x7c1
#define XK_Greek_BETA                                  0x7c2
#define XK_Greek_GAMMA                                 0x7c3
#define XK_Greek_DELTA                                 0x7c4
#define XK_Greek_EPSILON                               0x7c5
#define XK_Greek_ZETA                                  0x7c6
#define XK_Greek_ETA                                   0x7c7
#define XK_Greek_THETA                                 0x7c8
#define XK_Greek_IOTA                                  0x7c9
#define XK_Greek_KAPPA                                 0x7ca
#define XK_Greek_LAMDA                                 0x7cb
#define XK_Greek_LAMBDA                                0x7cb
#define XK_Greek_MU                                    0x7cc
#define XK_Greek_NU                                    0x7cd
#define XK_Greek_XI                                    0x7ce
#define XK_Greek_OMICRON                               0x7cf
#define XK_Greek_PI                                    0x7d0
#define XK_Greek_RHO                                   0x7d1
#define XK_Greek_SIGMA                                 0x7d2
#define XK_Greek_TAU                                   0x7d4
#define XK_Greek_UPSILON                               0x7d5
#define XK_Greek_PHI                                   0x7d6
#define XK_Greek_CHI                                   0x7d7
#define XK_Greek_PSI                                   0x7d8
#define XK_Greek_OMEGA                                 0x7d9
#define XK_Greek_alpha                                 0x7e1
#define XK_Greek_beta                                  0x7e2
#define XK_Greek_gamma                                 0x7e3
#define XK_Greek_delta                                 0x7e4
#define XK_Greek_epsilon                               0x7e5
#define XK_Greek_zeta                                  0x7e6
#define XK_Greek_eta                                   0x7e7
#define XK_Greek_theta                                 0x7e8
#define XK_Greek_iota                                  0x7e9
#define XK_Greek_kappa                                 0x7ea
#define XK_Greek_lamda                                 0x7eb
#define XK_Greek_lambda                                0x7eb
#define XK_Greek_mu                                    0x7ec
#define XK_Greek_nu                                    0x7ed
#define XK_Greek_xi                                    0x7ee
#define XK_Greek_omicron                               0x7ef
#define XK_Greek_pi                                    0x7f0
#define XK_Greek_rho                                   0x7f1
#define XK_Greek_sigma                                 0x7f2
#define XK_Greek_finalsmallsigma                       0x7f3
#define XK_Greek_tau                                   0x7f4
#define XK_Greek_upsilon                               0x7f5
#define XK_Greek_phi                                   0x7f6
#define XK_Greek_chi                                   0x7f7
#define XK_Greek_psi                                   0x7f8
#define XK_Greek_omega                                 0x7f9
#define XK_Greek_switch         0xFF7E  /* Alias for mode_switch */
#endif /* XK_GREEK */

/*
 * Technical
 * Byte 3 = 8
 */

#ifdef XK_TECHNICAL
#define XK_leftradical                                 0x8a1
#define XK_topleftradical                              0x8a2
#define XK_horizconnector                              0x8a3
#define XK_topintegral                                 0x8a4
#define XK_botintegral                                 0x8a5
#define XK_vertconnector                               0x8a6
#define XK_topleftsqbracket                            0x8a7
#define XK_botleftsqbracket                            0x8a8
#define XK_toprightsqbracket                           0x8a9
#define XK_botrightsqbracket                           0x8aa
#define XK_topleftparens                               0x8ab
#define XK_botleftparens                               0x8ac
#define XK_toprightparens                              0x8ad
#define XK_botrightparens                              0x8ae
#define XK_leftmiddlecurlybrace                        0x8af
#define XK_rightmiddlecurlybrace                       0x8b0
#define XK_topleftsummation                            0x8b1
#define XK_botleftsummation                            0x8b2
#define XK_topvertsummationconnector                   0x8b3
#define XK_botvertsummationconnector                   0x8b4
#define XK_toprightsummation                           0x8b5
#define XK_botrightsummation                           0x8b6
#define XK_rightmiddlesummation                        0x8b7
#define XK_lessthanequal                               0x8bc
#define XK_notequal                                    0x8bd
#define XK_greaterthanequal                            0x8be
#define XK_integral                                    0x8bf
#define XK_therefore                                   0x8c0
#define XK_variation                                   0x8c1
#define XK_infinity                                    0x8c2
#define XK_nabla                                       0x8c5
#define XK_approximate                                 0x8c8
#define XK_similarequal                                0x8c9
#define XK_ifonlyif                                    0x8cd
#define XK_implies                                     0x8ce
#define XK_identical                                   0x8cf
#define XK_radical                                     0x8d6
#define XK_includedin                                  0x8da
#define XK_includes                                    0x8db
#define XK_intersection                                0x8dc
#define XK_union                                       0x8dd
#define XK_logicaland                                  0x8de
#define XK_logicalor                                   0x8df
#define XK_partialderivative                           0x8ef
#define XK_function                                    0x8f6
#define XK_leftarrow                                   0x8fb
#define XK_uparrow                                     0x8fc
#define XK_rightarrow                                  0x8fd
#define XK_downarrow                                   0x8fe
#endif /* XK_TECHNICAL */

/*
 *  Special
 *  Byte 3 = 9
 */

#ifdef XK_SPECIAL
#define XK_blank                                       0x9df
#define XK_soliddiamond                                0x9e0
#define XK_checkerboard                                0x9e1
#define XK_ht                                          0x9e2
#define XK_ff                                          0x9e3
#define XK_cr                                          0x9e4
#define XK_lf                                          0x9e5
#define XK_nl                                          0x9e8
#define XK_vt                                          0x9e9
#define XK_lowrightcorner                              0x9ea
#define XK_uprightcorner                               0x9eb
#define XK_upleftcorner                                0x9ec
#define XK_lowleftcorner                               0x9ed
#define XK_crossinglines                               0x9ee
#define XK_horizlinescan1                              0x9ef
#define XK_horizlinescan3                              0x9f0
#define XK_horizlinescan5                              0x9f1
#define XK_horizlinescan7                              0x9f2
#define XK_horizlinescan9                              0x9f3
#define XK_leftt                                       0x9f4
#define XK_rightt                                      0x9f5
#define XK_bott                                        0x9f6
#define XK_topt                                        0x9f7
#define XK_vertbar                                     0x9f8
#endif /* XK_SPECIAL */

/*
 *  Publishing
 *  Byte 3 = a
 */

#ifdef XK_PUBLISHING
#define XK_emspace                                     0xaa1
#define XK_enspace                                     0xaa2
#define XK_em3space                                    0xaa3
#define XK_em4space                                    0xaa4
#define XK_digitspace                                  0xaa5
#define XK_punctspace                                  0xaa6
#define XK_thinspace                                   0xaa7
#define XK_hairspace                                   0xaa8
#define XK_emdash                                      0xaa9
#define XK_endash                                      0xaaa
#define XK_signifblank                                 0xaac
#define XK_ellipsis                                    0xaae
#define XK_doubbaselinedot                             0xaaf
#define XK_onethird                                    0xab0
#define XK_twothirds                                   0xab1
#define XK_onefifth                                    0xab2
#define XK_twofifths                                   0xab3
#define XK_threefifths                                 0xab4
#define XK_fourfifths                                  0xab5
#define XK_onesixth                                    0xab6
#define XK_fivesixths                                  0xab7
#define XK_careof                                      0xab8
#define XK_figdash                                     0xabb
#define XK_leftanglebracket                            0xabc
#define XK_decimalpoint                                0xabd
#define XK_rightanglebracket                           0xabe
#define XK_marker                                      0xabf
#define XK_oneeighth                                   0xac3
#define XK_threeeighths                                0xac4
#define XK_fiveeighths                                 0xac5
#define XK_seveneighths                                0xac6
#define XK_trademark                                   0xac9
#define XK_signaturemark                               0xaca
#define XK_trademarkincircle                           0xacb
#define XK_leftopentriangle                            0xacc
#define XK_rightopentriangle                           0xacd
#define XK_emopencircle                                0xace
#define XK_emopenrectangle                             0xacf
#define XK_leftsinglequotemark                         0xad0
#define XK_rightsinglequotemark                        0xad1
#define XK_leftdoublequotemark                         0xad2
#define XK_rightdoublequotemark                        0xad3
#define XK_prescription                                0xad4
#define XK_minutes                                     0xad6
#define XK_seconds                                     0xad7
#define XK_latincross                                  0xad9
#define XK_hexagram                                    0xada
#define XK_filledrectbullet                            0xadb
#define XK_filledlefttribullet                         0xadc
#define XK_filledrighttribullet                        0xadd
#define XK_emfilledcircle                              0xade
#define XK_emfilledrect                                0xadf
#define XK_enopencircbullet                            0xae0
#define XK_enopensquarebullet                          0xae1
#define XK_openrectbullet                              0xae2
#define XK_opentribulletup                             0xae3
#define XK_opentribulletdown                           0xae4
#define XK_openstar                                    0xae5
#define XK_enfilledcircbullet                          0xae6
#define XK_enfilledsqbullet                            0xae7
#define XK_filledtribulletup                           0xae8
#define XK_filledtribulletdown                         0xae9
#define XK_leftpointer                                 0xaea
#define XK_rightpointer                                0xaeb
#define XK_club                                        0xaec
#define XK_diamond                                     0xaed
#define XK_heart                                       0xaee
#define XK_maltesecross                                0xaf0
#define XK_dagger                                      0xaf1
#define XK_doubledagger                                0xaf2
#define XK_checkmark                                   0xaf3
#define XK_ballotcross                                 0xaf4
#define XK_musicalsharp                                0xaf5
#define XK_musicalflat                                 0xaf6
#define XK_malesymbol                                  0xaf7
#define XK_femalesymbol                                0xaf8
#define XK_telephone                                   0xaf9
#define XK_telephonerecorder                           0xafa
#define XK_phonographcopyright                         0xafb
#define XK_caret                                       0xafc
#define XK_singlelowquotemark                          0xafd
#define XK_doublelowquotemark                          0xafe
#define XK_cursor                                      0xaff
#endif /* XK_PUBLISHING */

/*
 *  APL
 *  Byte 3 = b
 */

#ifdef XK_APL
#define XK_leftcaret                                   0xba3
#define XK_rightcaret                                  0xba6
#define XK_downcaret                                   0xba8
#define XK_upcaret                                     0xba9
#define XK_overbar                                     0xbc0
#define XK_downtack                                    0xbc2
#define XK_upshoe                                      0xbc3
#define XK_downstile                                   0xbc4
#define XK_underbar                                    0xbc6
#define XK_jot                                         0xbca
#define XK_quad                                        0xbcc
#define XK_uptack                                      0xbce
#define XK_circle                                      0xbcf
#define XK_upstile                                     0xbd3
#define XK_downshoe                                    0xbd6
#define XK_rightshoe                                   0xbd8
#define XK_leftshoe                                    0xbda
#define XK_lefttack                                    0xbdc
#define XK_righttack                                   0xbfc
#endif /* XK_APL */

/*
 * Hebrew
 * Byte 3 = c
 */

#ifdef XK_HEBREW
#define XK_hebrew_doublelowline                        0xcdf
#define XK_hebrew_aleph                                0xce0
#define XK_hebrew_bet                                  0xce1
#define XK_hebrew_beth                                 0xce1  /* deprecated */
#define XK_hebrew_gimel                                0xce2
#define XK_hebrew_gimmel                               0xce2  /* deprecated */
#define XK_hebrew_dalet                                0xce3
#define XK_hebrew_daleth                               0xce3  /* deprecated */
#define XK_hebrew_he                                   0xce4
#define XK_hebrew_waw                                  0xce5
#define XK_hebrew_zain                                 0xce6
#define XK_hebrew_zayin                                0xce6  /* deprecated */
#define XK_hebrew_chet                                 0xce7
#define XK_hebrew_het                                  0xce7  /* deprecated */
#define XK_hebrew_tet                                  0xce8
#define XK_hebrew_teth                                 0xce8  /* deprecated */
#define XK_hebrew_yod                                  0xce9
#define XK_hebrew_finalkaph                            0xcea
#define XK_hebrew_kaph                                 0xceb
#define XK_hebrew_lamed                                0xcec
#define XK_hebrew_finalmem                             0xced
#define XK_hebrew_mem                                  0xcee
#define XK_hebrew_finalnun                             0xcef
#define XK_hebrew_nun                                  0xcf0
#define XK_hebrew_samech                               0xcf1
#define XK_hebrew_samekh                               0xcf1  /* deprecated */
#define XK_hebrew_ayin                                 0xcf2
#define XK_hebrew_finalpe                              0xcf3
#define XK_hebrew_pe                                   0xcf4
#define XK_hebrew_finalzade                            0xcf5
#define XK_hebrew_finalzadi                            0xcf5  /* deprecated */
#define XK_hebrew_zade                                 0xcf6
#define XK_hebrew_zadi                                 0xcf6  /* deprecated */
#define XK_hebrew_qoph                                 0xcf7
#define XK_hebrew_kuf                                  0xcf7  /* deprecated */
#define XK_hebrew_resh                                 0xcf8
#define XK_hebrew_shin                                 0xcf9
#define XK_hebrew_taw                                  0xcfa
#define XK_hebrew_taf                                  0xcfa  /* deprecated */
#define XK_Hebrew_switch        0xFF7E  /* Alias for mode_switch */
#endif /* XK_HEBREW */

/*
 * Copyright (c) 2000-2002 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 *
 * Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */
/*	$NetBSD: shm.h,v 1.15 1994/06/29 06:45:17 cgd Exp $	*/

/*
 * Copyright (c) 1994 Adam Glass
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by Adam Glass.
 * 4. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * As defined+described in "X/Open System Interfaces and Headers"
 *                         Issue 4, p. XXX
 */

#ifndef _SYS_SHM_H_
#define _SYS_SHM_H_

#include <sys/cdefs.h>
#include <sys/_types.h>

/*
 * [XSI]	All of the symbols from <sys/ipc.h> SHALL be defined
 *		when this header is included
 */
#include <sys/ipc.h>

/*
 * [XSI] The pid_t, time_t, key_t, and size_t types shall be defined as
 * described in <sys/types.h>.
 *
 * NOTE:	The definition of the key_t type is implicit from the
 *		inclusion of <sys/ipc.h>
 */
#include <sys/_types/_pid_t.h>
#include <sys/_types/_time_t.h>
#include <sys/_types/_size_t.h>

/*
 * [XSI] The unsigned integer type used for the number of current attaches
 * that MUST be able to store values at least as large as a type unsigned
 * short.
 */
typedef unsigned short  shmatt_t;


/*
 * Possible flag values which may be OR'ed into the third argument to
 * shmat()
 */
#define SHM_RDONLY      010000  /* [XSI] Attach read-only (else read-write) */
#define SHM_RND         020000  /* [XSI] Round attach address to SHMLBA */

/*
 * This value is symbolic, and generally not expected to be sed by user
 * programs directly, although such ise is permitted by the standard.  Its
 * value in our implementation is equal to the number of bytes per page.
 *
 * NOTE:	We DO NOT obtain this value from the appropriate system
 *		headers at this time, to avoid the resulting namespace
 *		pollution, which is why we discourages its use.
 */
#define SHMLBA      4096        /* [XSI] Segment low boundary address multiple*/

/* "official" access mode definitions; somewhat braindead since you have
 *  to specify (SHM_* >> 3) for group and (SHM_* >> 6) for world permissions */
#define SHM_R       (IPC_R)
#define SHM_W       (IPC_W)

#pragma pack(4)

/*
 * Technically, we should force all code references to the new structure
 * definition, not in just the standards conformance case, and leave the
 * legacy interface there for binary compatibility only.  Currently, we
 * are only forcing this for programs requesting standards conformance.
 */
#if __DARWIN_UNIX03 || defined(KERNEL)
/*
 * Structure used internally.
 *
 * This structure is exposed because standards dictate that it is used as
 * the third argment to shmctl().
 *
 * NOTE:	The field shm_internal is not meaningful in user space,
 *		and must not be used there.
 */
#if (defined(_POSIX_C_SOURCE) && !defined(_DARWIN_C_SOURCE))
struct shmid_ds
#else
#define shmid_ds        __shmid_ds_new
struct __shmid_ds_new
#endif
{
	struct __ipc_perm_new shm_perm; /* [XSI] Operation permission value */
	size_t          shm_segsz;      /* [XSI] Size of segment in bytes */
	pid_t           shm_lpid;       /* [XSI] PID of last shared memory op */
	pid_t           shm_cpid;       /* [XSI] PID of creator */
	shmatt_t        shm_nattch;     /* [XSI] Number of current attaches */
	time_t          shm_atime;      /* [XSI] Time of last shmat() */
	time_t          shm_dtime;      /* [XSI] Time of last shmdt() */
	time_t          shm_ctime;      /* [XSI] Time of last shmctl() change */
	void            *shm_internal;  /* reserved for kernel use */
};
#else   /* !__DARWIN_UNIX03 */
#define shmid_ds        __shmid_ds_old
#endif  /* !__DARWIN_UNIX03 */

#if !__DARWIN_UNIX03
struct __shmid_ds_old {
	struct __ipc_perm_old shm_perm; /* [XSI] Operation permission value */
	size_t          shm_segsz;      /* [XSI] Size of segment in bytes */
	pid_t           shm_lpid;       /* [XSI] PID of last shared memory op */
	pid_t           shm_cpid;       /* [XSI] PID of creator */
	shmatt_t        shm_nattch;     /* [XSI] Number of current attaches */
	time_t          shm_atime;      /* [XSI] Time of last shmat() */
	time_t          shm_dtime;      /* [XSI] Time of last shmdt() */
	time_t          shm_ctime;      /* [XSI] Time of last shmctl() change */
	void            *shm_internal;  /* reserved for kernel use */
};
#endif  /* !__DARWIN_UNIX03 */

#pragma pack()


__BEGIN_DECLS
#if !defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE)
int     shmsys(int, ...);
#endif /* (!_POSIX_C_SOURCE || _DARWIN_C_SOURCE) */
void    *shmat(int, const void *, int);
int     shmctl(int, int, struct shmid_ds *) __DARWIN_ALIAS(shmctl);
int     shmdt(const void *);
int     shmget(key_t, size_t, int);
__END_DECLS


#endif /* !_SYS_SHM_H_ */
/*
 * tkIntXlibDecls.h --
 *
 *	This file contains the declarations for all platform dependent
 *	unsupported functions that are exported by the Tk library.  These
 *	interfaces are not guaranteed to remain the same between
 *	versions.  Use at your own risk.
 *
 * Copyright (c) 1998-1999 by Scriptics Corporation.
 * All rights reserved.
 *
 * RCS: @(#) $Id$
 */

#ifndef _TKINTXLIBDECLS
#define _TKINTXLIBDECLS

#include "Xutil.h"

#ifdef BUILD_tk
#undef TCL_STORAGE_CLASS
#define TCL_STORAGE_CLASS DLLEXPORT
#endif

/*
 * WARNING: This file is automatically generated by the tools/genStubs.tcl
 * script.  Any modifications to the function declarations below should be made
 * in the generic/tkInt.decls script.
 */

/* !BEGIN!: Do not edit below this line. */

/*
 * Exported function declarations:
 */

#ifdef __WIN32__ /* WIN */
#ifndef XSetDashes_TCL_DECLARED
#define XSetDashes_TCL_DECLARED
/* 0 */
EXTERN void		XSetDashes(Display *display, GC gc, int dash_offset,
				_Xconst char *dash_list, int n);
#endif
#ifndef XGetModifierMapping_TCL_DECLARED
#define XGetModifierMapping_TCL_DECLARED
/* 1 */
EXTERN XModifierKeymap * XGetModifierMapping(Display *d);
#endif
#ifndef XCreateImage_TCL_DECLARED
#define XCreateImage_TCL_DECLARED
/* 2 */
EXTERN XImage *		XCreateImage(Display *d, Visual *v, unsigned int ui1,
				int i1, int i2, char *cp, unsigned int ui2,
				unsigned int ui3, int i3, int i4);
#endif
#ifndef XGetImage_TCL_DECLARED
#define XGetImage_TCL_DECLARED
/* 3 */
EXTERN XImage *		XGetImage(Display *d, Drawable dr, int i1, int i2,
				unsigned int ui1, unsigned int ui2,
				unsigned long ul, int i3);
#endif
#ifndef XGetAtomName_TCL_DECLARED
#define XGetAtomName_TCL_DECLARED
/* 4 */
EXTERN char *		XGetAtomName(Display *d, Atom a);
#endif
#ifndef XKeysymToString_TCL_DECLARED
#define XKeysymToString_TCL_DECLARED
/* 5 */
EXTERN char *		XKeysymToString(KeySym k);
#endif
#ifndef XCreateColormap_TCL_DECLARED
#define XCreateColormap_TCL_DECLARED
/* 6 */
EXTERN Colormap		XCreateColormap(Display *d, Window w, Visual *v,
				int i);
#endif
#ifndef XCreatePixmapCursor_TCL_DECLARED
#define XCreatePixmapCursor_TCL_DECLARED
/* 7 */
EXTERN Cursor		XCreatePixmapCursor(Display *d, Pixmap p1, Pixmap p2,
				XColor *x1, XColor *x2, unsigned int ui1,
				unsigned int ui2);
#endif
#ifndef XCreateGlyphCursor_TCL_DECLARED
#define XCreateGlyphCursor_TCL_DECLARED
/* 8 */
EXTERN Cursor		XCreateGlyphCursor(Display *d, Font f1, Font f2,
				unsigned int ui1, unsigned int ui2,
				XColor *x1, XColor *x2);
#endif
#ifndef XGContextFromGC_TCL_DECLARED
#define XGContextFromGC_TCL_DECLARED
/* 9 */
EXTERN GContext		XGContextFromGC(GC g);
#endif
#ifndef XListHosts_TCL_DECLARED
#define XListHosts_TCL_DECLARED
/* 10 */
EXTERN XHostAddress *	XListHosts(Display *d, int *i, Bool *b);
#endif
#ifndef XKeycodeToKeysym_TCL_DECLARED
#define XKeycodeToKeysym_TCL_DECLARED
/* 11 */
EXTERN KeySym		XKeycodeToKeysym(Display *d, unsigned int k, int i);
#endif
#ifndef XStringToKeysym_TCL_DECLARED
#define XStringToKeysym_TCL_DECLARED
/* 12 */
EXTERN KeySym		XStringToKeysym(_Xconst char *c);
#endif
#ifndef XRootWindow_TCL_DECLARED
#define XRootWindow_TCL_DECLARED
/* 13 */
EXTERN Window		XRootWindow(Display *d, int i);
#endif
#ifndef XSetErrorHandler_TCL_DECLARED
#define XSetErrorHandler_TCL_DECLARED
/* 14 */
EXTERN XErrorHandler	XSetErrorHandler(XErrorHandler x);
#endif
#ifndef XIconifyWindow_TCL_DECLARED
#define XIconifyWindow_TCL_DECLARED
/* 15 */
EXTERN Status		XIconifyWindow(Display *d, Window w, int i);
#endif
#ifndef XWithdrawWindow_TCL_DECLARED
#define XWithdrawWindow_TCL_DECLARED
/* 16 */
EXTERN Status		XWithdrawWindow(Display *d, Window w, int i);
#endif
#ifndef XGetWMColormapWindows_TCL_DECLARED
#define XGetWMColormapWindows_TCL_DECLARED
/* 17 */
EXTERN Status		XGetWMColormapWindows(Display *d, Window w,
				Window **wpp, int *ip);
#endif
#ifndef XAllocColor_TCL_DECLARED
#define XAllocColor_TCL_DECLARED
/* 18 */
EXTERN Status		XAllocColor(Display *d, Colormap c, XColor *xp);
#endif
#ifndef XBell_TCL_DECLARED
#define XBell_TCL_DECLARED
/* 19 */
EXTERN void		XBell(Display *d, int i);
#endif
#ifndef XChangeProperty_TCL_DECLARED
#define XChangeProperty_TCL_DECLARED
/* 20 */
EXTERN void		XChangeProperty(Display *d, Window w, Atom a1,
				Atom a2, int i1, int i2,
				_Xconst unsigned char *c, int i3);
#endif
#ifndef XChangeWindowAttributes_TCL_DECLARED
#define XChangeWindowAttributes_TCL_DECLARED
/* 21 */
EXTERN void		XChangeWindowAttributes(Display *d, Window w,
				unsigned long ul, XSetWindowAttributes *x);
#endif
#ifndef XClearWindow_TCL_DECLARED
#define XClearWindow_TCL_DECLARED
/* 22 */
EXTERN void		XClearWindow(Display *d, Window w);
#endif
#ifndef XConfigureWindow_TCL_DECLARED
#define XConfigureWindow_TCL_DECLARED
/* 23 */
EXTERN void		XConfigureWindow(Display *d, Window w,
				unsigned int i, XWindowChanges *x);
#endif
#ifndef XCopyArea_TCL_DECLARED
#define XCopyArea_TCL_DECLARED
/* 24 */
EXTERN void		XCopyArea(Display *d, Drawable dr1, Drawable dr2,
				GC g, int i1, int i2, unsigned int ui1,
				unsigned int ui2, int i3, int i4);
#endif
#ifndef XCopyPlane_TCL_DECLARED
#define XCopyPlane_TCL_DECLARED
/* 25 */
EXTERN void		XCopyPlane(Display *d, Drawable dr1, Drawable dr2,
				GC g, int i1, int i2, unsigned int ui1,
				unsigned int ui2, int i3, int i4,
				unsigned long ul);
#endif
#ifndef XCreateBitmapFromData_TCL_DECLARED
#define XCreateBitmapFromData_TCL_DECLARED
/* 26 */
EXTERN Pixmap		XCreateBitmapFromData(Display *display, Drawable d,
				_Xconst char *data, unsigned int width,
				unsigned int height);
#endif
#ifndef XDefineCursor_TCL_DECLARED
#define XDefineCursor_TCL_DECLARED
/* 27 */
EXTERN void		XDefineCursor(Display *d, Window w, Cursor c);
#endif
#ifndef XDeleteProperty_TCL_DECLARED
#define XDeleteProperty_TCL_DECLARED
/* 28 */
EXTERN void		XDeleteProperty(Display *d, Window w, Atom a);
#endif
#ifndef XDestroyWindow_TCL_DECLARED
#define XDestroyWindow_TCL_DECLARED
/* 29 */
EXTERN void		XDestroyWindow(Display *d, Window w);
#endif
#ifndef XDrawArc_TCL_DECLARED
#define XDrawArc_TCL_DECLARED
/* 30 */
EXTERN void		XDrawArc(Display *d, Drawable dr, GC g, int i1,
				int i2, unsigned int ui1, unsigned int ui2,
				int i3, int i4);
#endif
#ifndef XDrawLines_TCL_DECLARED
#define XDrawLines_TCL_DECLARED
/* 31 */
EXTERN void		XDrawLines(Display *d, Drawable dr, GC g, XPoint *x,
				int i1, int i2);
#endif
#ifndef XDrawRectangle_TCL_DECLARED
#define XDrawRectangle_TCL_DECLARED
/* 32 */
EXTERN void		XDrawRectangle(Display *d, Drawable dr, GC g, int i1,
				int i2, unsigned int ui1, unsigned int ui2);
#endif
#ifndef XFillArc_TCL_DECLARED
#define XFillArc_TCL_DECLARED
/* 33 */
EXTERN void		XFillArc(Display *d, Drawable dr, GC g, int i1,
				int i2, unsigned int ui1, unsigned int ui2,
				int i3, int i4);
#endif
#ifndef XFillPolygon_TCL_DECLARED
#define XFillPolygon_TCL_DECLARED
/* 34 */
EXTERN void		XFillPolygon(Display *d, Drawable dr, GC g,
				XPoint *x, int i1, int i2, int i3);
#endif
#ifndef XFillRectangles_TCL_DECLARED
#define XFillRectangles_TCL_DECLARED
/* 35 */
EXTERN void		XFillRectangles(Display *d, Drawable dr, GC g,
				XRectangle *x, int i);
#endif
#ifndef XForceScreenSaver_TCL_DECLARED
#define XForceScreenSaver_TCL_DECLARED
/* 36 */
EXTERN void		XForceScreenSaver(Display *d, int i);
#endif
#ifndef XFreeColormap_TCL_DECLARED
#define XFreeColormap_TCL_DECLARED
/* 37 */
EXTERN void		XFreeColormap(Display *d, Colormap c);
#endif
#ifndef XFreeColors_TCL_DECLARED
#define XFreeColors_TCL_DECLARED
/* 38 */
EXTERN void		XFreeColors(Display *d, Colormap c,
				unsigned long *ulp, int i, unsigned long ul);
#endif
#ifndef XFreeCursor_TCL_DECLARED
#define XFreeCursor_TCL_DECLARED
/* 39 */
EXTERN void		XFreeCursor(Display *d, Cursor c);
#endif
#ifndef XFreeModifiermap_TCL_DECLARED
#define XFreeModifiermap_TCL_DECLARED
/* 40 */
EXTERN void		XFreeModifiermap(XModifierKeymap *x);
#endif
#ifndef XGetGeometry_TCL_DECLARED
#define XGetGeometry_TCL_DECLARED
/* 41 */
EXTERN Status		XGetGeometry(Display *d, Drawable dr, Window *w,
				int *i1, int *i2, unsigned int *ui1,
				unsigned int *ui2, unsigned int *ui3,
				unsigned int *ui4);
#endif
#ifndef XGetInputFocus_TCL_DECLARED
#define XGetInputFocus_TCL_DECLARED
/* 42 */
EXTERN void		XGetInputFocus(Display *d, Window *w, int *i);
#endif
#ifndef XGetWindowProperty_TCL_DECLARED
#define XGetWindowProperty_TCL_DECLARED
/* 43 */
EXTERN int		XGetWindowProperty(Display *d, Window w, Atom a1,
				long l1, long l2, Bool b, Atom a2, Atom *ap,
				int *ip, unsigned long *ulp1,
				unsigned long *ulp2, unsigned char **cpp);
#endif
#ifndef XGetWindowAttributes_TCL_DECLARED
#define XGetWindowAttributes_TCL_DECLARED
/* 44 */
EXTERN Status		XGetWindowAttributes(Display *d, Window w,
				XWindowAttributes *x);
#endif
#ifndef XGrabKeyboard_TCL_DECLARED
#define XGrabKeyboard_TCL_DECLARED
/* 45 */
EXTERN int		XGrabKeyboard(Display *d, Window w, Bool b, int i1,
				int i2, Time t);
#endif
#ifndef XGrabPointer_TCL_DECLARED
#define XGrabPointer_TCL_DECLARED
/* 46 */
EXTERN int		XGrabPointer(Display *d, Window w1, Bool b,
				unsigned int ui, int i1, int i2, Window w2,
				Cursor c, Time t);
#endif
#ifndef XKeysymToKeycode_TCL_DECLARED
#define XKeysymToKeycode_TCL_DECLARED
/* 47 */
EXTERN KeyCode		XKeysymToKeycode(Display *d, KeySym k);
#endif
#ifndef XLookupColor_TCL_DECLARED
#define XLookupColor_TCL_DECLARED
/* 48 */
EXTERN Status		XLookupColor(Display *d, Colormap c1,
				_Xconst char *c2, XColor *x1, XColor *x2);
#endif
#ifndef XMapWindow_TCL_DECLARED
#define XMapWindow_TCL_DECLARED
/* 49 */
EXTERN void		XMapWindow(Display *d, Window w);
#endif
#ifndef XMoveResizeWindow_TCL_DECLARED
#define XMoveResizeWindow_TCL_DECLARED
/* 50 */
EXTERN void		XMoveResizeWindow(Display *d, Window w, int i1,
				int i2, unsigned int ui1, unsigned int ui2);
#endif
#ifndef XMoveWindow_TCL_DECLARED
#define XMoveWindow_TCL_DECLARED
/* 51 */
EXTERN void		XMoveWindow(Display *d, Window w, int i1, int i2);
#endif
#ifndef XNextEvent_TCL_DECLARED
#define XNextEvent_TCL_DECLARED
/* 52 */
EXTERN void		XNextEvent(Display *d, XEvent *x);
#endif
#ifndef XPutBackEvent_TCL_DECLARED
#define XPutBackEvent_TCL_DECLARED
/* 53 */
EXTERN void		XPutBackEvent(Display *d, XEvent *x);
#endif
#ifndef XQueryColors_TCL_DECLARED
#define XQueryColors_TCL_DECLARED
/* 54 */
EXTERN void		XQueryColors(Display *d, Colormap c, XColor *x,
				int i);
#endif
#ifndef XQueryPointer_TCL_DECLARED
#define XQueryPointer_TCL_DECLARED
/* 55 */
EXTERN Bool		XQueryPointer(Display *d, Window w1, Window *w2,
				Window *w3, int *i1, int *i2, int *i3,
				int *i4, unsigned int *ui);
#endif
#ifndef XQueryTree_TCL_DECLARED
#define XQueryTree_TCL_DECLARED
/* 56 */
EXTERN Status		XQueryTree(Display *d, Window w1, Window *w2,
				Window *w3, Window **w4, unsigned int *ui);
#endif
#ifndef XRaiseWindow_TCL_DECLARED
#define XRaiseWindow_TCL_DECLARED
/* 57 */
EXTERN void		XRaiseWindow(Display *d, Window w);
#endif
#ifndef XRefreshKeyboardMapping_TCL_DECLARED
#define XRefreshKeyboardMapping_TCL_DECLARED
/* 58 */
EXTERN void		XRefreshKeyboardMapping(XMappingEvent *x);
#endif
#ifndef XResizeWindow_TCL_DECLARED
#define XResizeWindow_TCL_DECLARED
/* 59 */
EXTERN void		XResizeWindow(Display *d, Window w, unsigned int ui1,
				unsigned int ui2);
#endif
#ifndef XSelectInput_TCL_DECLARED
#define XSelectInput_TCL_DECLARED
/* 60 */
EXTERN void		XSelectInput(Display *d, Window w, long l);
#endif
#ifndef XSendEvent_TCL_DECLARED
#define XSendEvent_TCL_DECLARED
/* 61 */
EXTERN Status		XSendEvent(Display *d, Window w, Bool b, long l,
				XEvent *x);
#endif
#ifndef XSetCommand_TCL_DECLARED
#define XSetCommand_TCL_DECLARED
/* 62 */
EXTERN void		XSetCommand(Display *d, Window w, CONST char **c,
				int i);
#endif
#ifndef XSetIconName_TCL_DECLARED
#define XSetIconName_TCL_DECLARED
/* 63 */
EXTERN void		XSetIconName(Display *d, Window w, _Xconst char *c);
#endif
#ifndef XSetInputFocus_TCL_DECLARED
#define XSetInputFocus_TCL_DECLARED
/* 64 */
EXTERN void		XSetInputFocus(Display *d, Window w, int i, Time t);
#endif
#ifndef XSetSelectionOwner_TCL_DECLARED
#define XSetSelectionOwner_TCL_DECLARED
/* 65 */
EXTERN void		XSetSelectionOwner(Display *d, Atom a, Window w,
				Time t);
#endif
#ifndef XSetWindowBackground_TCL_DECLARED
#define XSetWindowBackground_TCL_DECLARED
/* 66 */
EXTERN void		XSetWindowBackground(Display *d, Window w,
				unsigned long ul);
#endif
#ifndef XSetWindowBackgroundPixmap_TCL_DECLARED
#define XSetWindowBackgroundPixmap_TCL_DECLARED
/* 67 */
EXTERN void		XSetWindowBackgroundPixmap(Display *d, Window w,
				Pixmap p);
#endif
#ifndef XSetWindowBorder_TCL_DECLARED
#define XSetWindowBorder_TCL_DECLARED
/* 68 */
EXTERN void		XSetWindowBorder(Display *d, Window w,
				unsigned long ul);
#endif
#ifndef XSetWindowBorderPixmap_TCL_DECLARED
#define XSetWindowBorderPixmap_TCL_DECLARED
/* 69 */
EXTERN void		XSetWindowBorderPixmap(Display *d, Window w,
				Pixmap p);
#endif
#ifndef XSetWindowBorderWidth_TCL_DECLARED
#define XSetWindowBorderWidth_TCL_DECLARED
/* 70 */
EXTERN void		XSetWindowBorderWidth(Display *d, Window w,
				unsigned int ui);
#endif
#ifndef XSetWindowColormap_TCL_DECLARED
#define XSetWindowColormap_TCL_DECLARED
/* 71 */
EXTERN void		XSetWindowColormap(Display *d, Window w, Colormap c);
#endif
#ifndef XTranslateCoordinates_TCL_DECLARED
#define XTranslateCoordinates_TCL_DECLARED
/* 72 */
EXTERN Bool		XTranslateCoordinates(Display *d, Window w1,
				Window w2, int i1, int i2, int *i3, int *i4,
				Window *w3);
#endif
#ifndef XUngrabKeyboard_TCL_DECLARED
#define XUngrabKeyboard_TCL_DECLARED
/* 73 */
EXTERN void		XUngrabKeyboard(Display *d, Time t);
#endif
#ifndef XUngrabPointer_TCL_DECLARED
#define XUngrabPointer_TCL_DECLARED
/* 74 */
EXTERN void		XUngrabPointer(Display *d, Time t);
#endif
#ifndef XUnmapWindow_TCL_DECLARED
#define XUnmapWindow_TCL_DECLARED
/* 75 */
EXTERN void		XUnmapWindow(Display *d, Window w);
#endif
#ifndef XWindowEvent_TCL_DECLARED
#define XWindowEvent_TCL_DECLARED
/* 76 */
EXTERN void		XWindowEvent(Display *d, Window w, long l, XEvent *x);
#endif
#ifndef XDestroyIC_TCL_DECLARED
#define XDestroyIC_TCL_DECLARED
/* 77 */
EXTERN void		XDestroyIC(XIC x);
#endif
#ifndef XFilterEvent_TCL_DECLARED
#define XFilterEvent_TCL_DECLARED
/* 78 */
EXTERN Bool		XFilterEvent(XEvent *x, Window w);
#endif
#ifndef XmbLookupString_TCL_DECLARED
#define XmbLookupString_TCL_DECLARED
/* 79 */
EXTERN int		XmbLookupString(XIC xi, XKeyPressedEvent *xk,
				char *c, int i, KeySym *k, Status *s);
#endif
#ifndef TkPutImage_TCL_DECLARED
#define TkPutImage_TCL_DECLARED
/* 80 */
EXTERN void		TkPutImage(unsigned long *colors, int ncolors,
				Display *display, Drawable d, GC gc,
				XImage *image, int src_x, int src_y,
				int dest_x, int dest_y, unsigned int width,
				unsigned int height);
#endif
/* Slot 81 is reserved */
#ifndef XParseColor_TCL_DECLARED
#define XParseColor_TCL_DECLARED
/* 82 */
EXTERN Status		XParseColor(Display *display, Colormap map,
				_Xconst char *spec, XColor *colorPtr);
#endif
#ifndef XCreateGC_TCL_DECLARED
#define XCreateGC_TCL_DECLARED
/* 83 */
EXTERN GC		XCreateGC(Display *display, Drawable d,
				unsigned long valuemask, XGCValues *values);
#endif
#ifndef XFreeGC_TCL_DECLARED
#define XFreeGC_TCL_DECLARED
/* 84 */
EXTERN void		XFreeGC(Display *display, GC gc);
#endif
#ifndef XInternAtom_TCL_DECLARED
#define XInternAtom_TCL_DECLARED
/* 85 */
EXTERN Atom		XInternAtom(Display *display,
				_Xconst char *atom_name, Bool only_if_exists);
#endif
#ifndef XSetBackground_TCL_DECLARED
#define XSetBackground_TCL_DECLARED
/* 86 */
EXTERN void		XSetBackground(Display *display, GC gc,
				unsigned long foreground);
#endif
#ifndef XSetForeground_TCL_DECLARED
#define XSetForeground_TCL_DECLARED
/* 87 */
EXTERN void		XSetForeground(Display *display, GC gc,
				unsigned long foreground);
#endif
#ifndef XSetClipMask_TCL_DECLARED
#define XSetClipMask_TCL_DECLARED
/* 88 */
EXTERN void		XSetClipMask(Display *display, GC gc, Pixmap pixmap);
#endif
#ifndef XSetClipOrigin_TCL_DECLARED
#define XSetClipOrigin_TCL_DECLARED
/* 89 */
EXTERN void		XSetClipOrigin(Display *display, GC gc,
				int clip_x_origin, int clip_y_origin);
#endif
#ifndef XSetTSOrigin_TCL_DECLARED
#define XSetTSOrigin_TCL_DECLARED
/* 90 */
EXTERN void		XSetTSOrigin(Display *display, GC gc,
				int ts_x_origin, int ts_y_origin);
#endif
#ifndef XChangeGC_TCL_DECLARED
#define XChangeGC_TCL_DECLARED
/* 91 */
EXTERN void		XChangeGC(Display *d, GC gc, unsigned long mask,
				XGCValues *values);
#endif
#ifndef XSetFont_TCL_DECLARED
#define XSetFont_TCL_DECLARED
/* 92 */
EXTERN void		XSetFont(Display *display, GC gc, Font font);
#endif
#ifndef XSetArcMode_TCL_DECLARED
#define XSetArcMode_TCL_DECLARED
/* 93 */
EXTERN void		XSetArcMode(Display *display, GC gc, int arc_mode);
#endif
#ifndef XSetStipple_TCL_DECLARED
#define XSetStipple_TCL_DECLARED
/* 94 */
EXTERN void		XSetStipple(Display *display, GC gc, Pixmap stipple);
#endif
#ifndef XSetFillRule_TCL_DECLARED
#define XSetFillRule_TCL_DECLARED
/* 95 */
EXTERN void		XSetFillRule(Display *display, GC gc, int fill_rule);
#endif
#ifndef XSetFillStyle_TCL_DECLARED
#define XSetFillStyle_TCL_DECLARED
/* 96 */
EXTERN void		XSetFillStyle(Display *display, GC gc,
				int fill_style);
#endif
#ifndef XSetFunction_TCL_DECLARED
#define XSetFunction_TCL_DECLARED
/* 97 */
EXTERN void		XSetFunction(Display *display, GC gc, int function);
#endif
#ifndef XSetLineAttributes_TCL_DECLARED
#define XSetLineAttributes_TCL_DECLARED
/* 98 */
EXTERN void		XSetLineAttributes(Display *display, GC gc,
				unsigned int line_width, int line_style,
				int cap_style, int join_style);
#endif
#ifndef _XInitImageFuncPtrs_TCL_DECLARED
#define _XInitImageFuncPtrs_TCL_DECLARED
/* 99 */
EXTERN int		_XInitImageFuncPtrs(XImage *image);
#endif
#ifndef XCreateIC_TCL_DECLARED
#define XCreateIC_TCL_DECLARED
/* 100 */
EXTERN XIC		XCreateIC(void);
#endif
#ifndef XGetVisualInfo_TCL_DECLARED
#define XGetVisualInfo_TCL_DECLARED
/* 101 */
EXTERN XVisualInfo *	XGetVisualInfo(Display *display, long vinfo_mask,
				XVisualInfo *vinfo_template,
				int *nitems_return);
#endif
#ifndef XSetWMClientMachine_TCL_DECLARED
#define XSetWMClientMachine_TCL_DECLARED
/* 102 */
EXTERN void		XSetWMClientMachine(Display *display, Window w,
				XTextProperty *text_prop);
#endif
#ifndef XStringListToTextProperty_TCL_DECLARED
#define XStringListToTextProperty_TCL_DECLARED
/* 103 */
EXTERN Status		XStringListToTextProperty(char **list, int count,
				XTextProperty *text_prop_return);
#endif
#ifndef XDrawLine_TCL_DECLARED
#define XDrawLine_TCL_DECLARED
/* 104 */
EXTERN void		XDrawLine(Display *d, Drawable dr, GC g, int x1,
				int y1, int x2, int y2);
#endif
#ifndef XWarpPointer_TCL_DECLARED
#define XWarpPointer_TCL_DECLARED
/* 105 */
EXTERN void		XWarpPointer(Display *d, Window s, Window dw, int sx,
				int sy, unsigned int sw, unsigned int sh,
				int dx, int dy);
#endif
#ifndef XFillRectangle_TCL_DECLARED
#define XFillRectangle_TCL_DECLARED
/* 106 */
EXTERN void		XFillRectangle(Display *display, Drawable d, GC gc,
				int x, int y, unsigned int width,
				unsigned int height);
#endif
#endif /* WIN */
#ifdef MAC_OSX_TK /* AQUA */
#ifndef XSetDashes_TCL_DECLARED
#define XSetDashes_TCL_DECLARED
/* 0 */
EXTERN void		XSetDashes(Display *display, GC gc, int dash_offset,
				_Xconst char *dash_list, int n);
#endif
#ifndef XGetModifierMapping_TCL_DECLARED
#define XGetModifierMapping_TCL_DECLARED
/* 1 */
EXTERN XModifierKeymap * XGetModifierMapping(Display *d);
#endif
#ifndef XCreateImage_TCL_DECLARED
#define XCreateImage_TCL_DECLARED
/* 2 */
EXTERN XImage *		XCreateImage(Display *d, Visual *v, unsigned int ui1,
				int i1, int i2, char *cp, unsigned int ui2,
				unsigned int ui3, int i3, int i4);
#endif
#ifndef XGetImage_TCL_DECLARED
#define XGetImage_TCL_DECLARED
/* 3 */
EXTERN XImage *		XGetImage(Display *d, Drawable dr, int i1, int i2,
				unsigned int ui1, unsigned int ui2,
				unsigned long ul, int i3);
#endif
#ifndef XGetAtomName_TCL_DECLARED
#define XGetAtomName_TCL_DECLARED
/* 4 */
EXTERN char *		XGetAtomName(Display *d, Atom a);
#endif
#ifndef XKeysymToString_TCL_DECLARED
#define XKeysymToString_TCL_DECLARED
/* 5 */
EXTERN char *		XKeysymToString(KeySym k);
#endif
#ifndef XCreateColormap_TCL_DECLARED
#define XCreateColormap_TCL_DECLARED
/* 6 */
EXTERN Colormap		XCreateColormap(Display *d, Window w, Visual *v,
				int i);
#endif
#ifndef XGContextFromGC_TCL_DECLARED
#define XGContextFromGC_TCL_DECLARED
/* 7 */
EXTERN GContext		XGContextFromGC(GC g);
#endif
#ifndef XKeycodeToKeysym_TCL_DECLARED
#define XKeycodeToKeysym_TCL_DECLARED
/* 8 */
EXTERN KeySym		XKeycodeToKeysym(Display *d, KeyCode k, int i);
#endif
#ifndef XStringToKeysym_TCL_DECLARED
#define XStringToKeysym_TCL_DECLARED
/* 9 */
EXTERN KeySym		XStringToKeysym(_Xconst char *c);
#endif
#ifndef XRootWindow_TCL_DECLARED
#define XRootWindow_TCL_DECLARED
/* 10 */
EXTERN Window		XRootWindow(Display *d, int i);
#endif
#ifndef XSetErrorHandler_TCL_DECLARED
#define XSetErrorHandler_TCL_DECLARED
/* 11 */
EXTERN XErrorHandler	XSetErrorHandler(XErrorHandler x);
#endif
#ifndef XAllocColor_TCL_DECLARED
#define XAllocColor_TCL_DECLARED
/* 12 */
EXTERN Status		XAllocColor(Display *d, Colormap c, XColor *xp);
#endif
#ifndef XBell_TCL_DECLARED
#define XBell_TCL_DECLARED
/* 13 */
EXTERN void		XBell(Display *d, int i);
#endif
#ifndef XChangeProperty_TCL_DECLARED
#define XChangeProperty_TCL_DECLARED
/* 14 */
EXTERN void		XChangeProperty(Display *d, Window w, Atom a1,
				Atom a2, int i1, int i2,
				_Xconst unsigned char *c, int i3);
#endif
#ifndef XChangeWindowAttributes_TCL_DECLARED
#define XChangeWindowAttributes_TCL_DECLARED
/* 15 */
EXTERN void		XChangeWindowAttributes(Display *d, Window w,
				unsigned long ul, XSetWindowAttributes *x);
#endif
#ifndef XConfigureWindow_TCL_DECLARED
#define XConfigureWindow_TCL_DECLARED
/* 16 */
EXTERN void		XConfigureWindow(Display *d, Window w,
				unsigned int i, XWindowChanges *x);
#endif
#ifndef XCopyArea_TCL_DECLARED
#define XCopyArea_TCL_DECLARED
/* 17 */
EXTERN void		XCopyArea(Display *d, Drawable dr1, Drawable dr2,
				GC g, int i1, int i2, unsigned int ui1,
				unsigned int ui2, int i3, int i4);
#endif
#ifndef XCopyPlane_TCL_DECLARED
#define XCopyPlane_TCL_DECLARED
/* 18 */
EXTERN void		XCopyPlane(Display *d, Drawable dr1, Drawable dr2,
				GC g, int i1, int i2, unsigned int ui1,
				unsigned int ui2, int i3, int i4,
				unsigned long ul);
#endif
#ifndef XCreateBitmapFromData_TCL_DECLARED
#define XCreateBitmapFromData_TCL_DECLARED
/* 19 */
EXTERN Pixmap		XCreateBitmapFromData(Display *display, Drawable d,
				_Xconst char *data, unsigned int width,
				unsigned int height);
#endif
#ifndef XDefineCursor_TCL_DECLARED
#define XDefineCursor_TCL_DECLARED
/* 20 */
EXTERN void		XDefineCursor(Display *d, Window w, Cursor c);
#endif
#ifndef XDestroyWindow_TCL_DECLARED
#define XDestroyWindow_TCL_DECLARED
/* 21 */
EXTERN void		XDestroyWindow(Display *d, Window w);
#endif
#ifndef XDrawArc_TCL_DECLARED
#define XDrawArc_TCL_DECLARED
/* 22 */
EXTERN void		XDrawArc(Display *d, Drawable dr, GC g, int i1,
				int i2, unsigned int ui1, unsigned int ui2,
				int i3, int i4);
#endif
#ifndef XDrawLines_TCL_DECLARED
#define XDrawLines_TCL_DECLARED
/* 23 */
EXTERN void		XDrawLines(Display *d, Drawable dr, GC g, XPoint *x,
				int i1, int i2);
#endif
#ifndef XDrawRectangle_TCL_DECLARED
#define XDrawRectangle_TCL_DECLARED
/* 24 */
EXTERN void		XDrawRectangle(Display *d, Drawable dr, GC g, int i1,
				int i2, unsigned int ui1, unsigned int ui2);
#endif
#ifndef XFillArc_TCL_DECLARED
#define XFillArc_TCL_DECLARED
/* 25 */
EXTERN void		XFillArc(Display *d, Drawable dr, GC g, int i1,
				int i2, unsigned int ui1, unsigned int ui2,
				int i3, int i4);
#endif
#ifndef XFillPolygon_TCL_DECLARED
#define XFillPolygon_TCL_DECLARED
/* 26 */
EXTERN void		XFillPolygon(Display *d, Drawable dr, GC g,
				XPoint *x, int i1, int i2, int i3);
#endif
#ifndef XFillRectangles_TCL_DECLARED
#define XFillRectangles_TCL_DECLARED
/* 27 */
EXTERN void		XFillRectangles(Display *d, Drawable dr, GC g,
				XRectangle *x, int i);
#endif
#ifndef XFreeColormap_TCL_DECLARED
#define XFreeColormap_TCL_DECLARED
/* 28 */
EXTERN void		XFreeColormap(Display *d, Colormap c);
#endif
#ifndef XFreeColors_TCL_DECLARED
#define XFreeColors_TCL_DECLARED
/* 29 */
EXTERN void		XFreeColors(Display *d, Colormap c,
				unsigned long *ulp, int i, unsigned long ul);
#endif
#ifndef XFreeModifiermap_TCL_DECLARED
#define XFreeModifiermap_TCL_DECLARED
/* 30 */
EXTERN void		XFreeModifiermap(XModifierKeymap *x);
#endif
#ifndef XGetGeometry_TCL_DECLARED
#define XGetGeometry_TCL_DECLARED
/* 31 */
EXTERN Status		XGetGeometry(Display *d, Drawable dr, Window *w,
				int *i1, int *i2, unsigned int *ui1,
				unsigned int *ui2, unsigned int *ui3,
				unsigned int *ui4);
#endif
#ifndef XGetWindowProperty_TCL_DECLARED
#define XGetWindowProperty_TCL_DECLARED
/* 32 */
EXTERN int		XGetWindowProperty(Display *d, Window w, Atom a1,
				long l1, long l2, Bool b, Atom a2, Atom *ap,
				int *ip, unsigned long *ulp1,
				unsigned long *ulp2, unsigned char **cpp);
#endif
#ifndef XGrabKeyboard_TCL_DECLARED
#define XGrabKeyboard_TCL_DECLARED
/* 33 */
EXTERN int		XGrabKeyboard(Display *d, Window w, Bool b, int i1,
				int i2, Time t);
#endif
#ifndef XGrabPointer_TCL_DECLARED
#define XGrabPointer_TCL_DECLARED
/* 34 */
EXTERN int		XGrabPointer(Display *d, Window w1, Bool b,
				unsigned int ui, int i1, int i2, Window w2,
				Cursor c, Time t);
#endif
#ifndef XKeysymToKeycode_TCL_DECLARED
#define XKeysymToKeycode_TCL_DECLARED
/* 35 */
EXTERN KeyCode		XKeysymToKeycode(Display *d, KeySym k);
#endif
#ifndef XMapWindow_TCL_DECLARED
#define XMapWindow_TCL_DECLARED
/* 36 */
EXTERN void		XMapWindow(Display *d, Window w);
#endif
#ifndef XMoveResizeWindow_TCL_DECLARED
#define XMoveResizeWindow_TCL_DECLARED
/* 37 */
EXTERN void		XMoveResizeWindow(Display *d, Window w, int i1,
				int i2, unsigned int ui1, unsigned int ui2);
#endif
#ifndef XMoveWindow_TCL_DECLARED
#define XMoveWindow_TCL_DECLARED
/* 38 */
EXTERN void		XMoveWindow(Display *d, Window w, int i1, int i2);
#endif
#ifndef XQueryPointer_TCL_DECLARED
#define XQueryPointer_TCL_DECLARED
/* 39 */
EXTERN Bool		XQueryPointer(Display *d, Window w1, Window *w2,
				Window *w3, int *i1, int *i2, int *i3,
				int *i4, unsigned int *ui);
#endif
#ifndef XRaiseWindow_TCL_DECLARED
#define XRaiseWindow_TCL_DECLARED
/* 40 */
EXTERN void		XRaiseWindow(Display *d, Window w);
#endif
#ifndef XRefreshKeyboardMapping_TCL_DECLARED
#define XRefreshKeyboardMapping_TCL_DECLARED
/* 41 */
EXTERN void		XRefreshKeyboardMapping(XMappingEvent *x);
#endif
#ifndef XResizeWindow_TCL_DECLARED
#define XResizeWindow_TCL_DECLARED
/* 42 */
EXTERN void		XResizeWindow(Display *d, Window w, unsigned int ui1,
				unsigned int ui2);
#endif
#ifndef XSelectInput_TCL_DECLARED
#define XSelectInput_TCL_DECLARED
/* 43 */
EXTERN void		XSelectInput(Display *d, Window w, long l);
#endif
#ifndef XSendEvent_TCL_DECLARED
#define XSendEvent_TCL_DECLARED
/* 44 */
EXTERN Status		XSendEvent(Display *d, Window w, Bool b, long l,
				XEvent *x);
#endif
#ifndef XSetIconName_TCL_DECLARED
#define XSetIconName_TCL_DECLARED
/* 45 */
EXTERN void		XSetIconName(Display *d, Window w, _Xconst char *c);
#endif
#ifndef XSetInputFocus_TCL_DECLARED
#define XSetInputFocus_TCL_DECLARED
/* 46 */
EXTERN void		XSetInputFocus(Display *d, Window w, int i, Time t);
#endif
#ifndef XSetSelectionOwner_TCL_DECLARED
#define XSetSelectionOwner_TCL_DECLARED
/* 47 */
EXTERN void		XSetSelectionOwner(Display *d, Atom a, Window w,
				Time t);
#endif
#ifndef XSetWindowBackground_TCL_DECLARED
#define XSetWindowBackground_TCL_DECLARED
/* 48 */
EXTERN void		XSetWindowBackground(Display *d, Window w,
				unsigned long ul);
#endif
#ifndef XSetWindowBackgroundPixmap_TCL_DECLARED
#define XSetWindowBackgroundPixmap_TCL_DECLARED
/* 49 */
EXTERN void		XSetWindowBackgroundPixmap(Display *d, Window w,
				Pixmap p);
#endif
#ifndef XSetWindowBorder_TCL_DECLARED
#define XSetWindowBorder_TCL_DECLARED
/* 50 */
EXTERN void		XSetWindowBorder(Display *d, Window w,
				unsigned long ul);
#endif
#ifndef XSetWindowBorderPixmap_TCL_DECLARED
#define XSetWindowBorderPixmap_TCL_DECLARED
/* 51 */
EXTERN void		XSetWindowBorderPixmap(Display *d, Window w,
				Pixmap p);
#endif
#ifndef XSetWindowBorderWidth_TCL_DECLARED
#define XSetWindowBorderWidth_TCL_DECLARED
/* 52 */
EXTERN void		XSetWindowBorderWidth(Display *d, Window w,
				unsigned int ui);
#endif
#ifndef XSetWindowColormap_TCL_DECLARED
#define XSetWindowColormap_TCL_DECLARED
/* 53 */
EXTERN void		XSetWindowColormap(Display *d, Window w, Colormap c);
#endif
#ifndef XUngrabKeyboard_TCL_DECLARED
#define XUngrabKeyboard_TCL_DECLARED
/* 54 */
EXTERN void		XUngrabKeyboard(Display *d, Time t);
#endif
#ifndef XUngrabPointer_TCL_DECLARED
#define XUngrabPointer_TCL_DECLARED
/* 55 */
EXTERN void		XUngrabPointer(Display *d, Time t);
#endif
#ifndef XUnmapWindow_TCL_DECLARED
#define XUnmapWindow_TCL_DECLARED
/* 56 */
EXTERN void		XUnmapWindow(Display *d, Window w);
#endif
#ifndef TkPutImage_TCL_DECLARED
#define TkPutImage_TCL_DECLARED
/* 57 */
EXTERN void		TkPutImage(unsigned long *colors, int ncolors,
				Display *display, Drawable d, GC gc,
				XImage *image, int src_x, int src_y,
				int dest_x, int dest_y, unsigned int width,
				unsigned int height);
#endif
#ifndef XParseColor_TCL_DECLARED
#define XParseColor_TCL_DECLARED
/* 58 */
EXTERN Status		XParseColor(Display *display, Colormap map,
				_Xconst char *spec, XColor *colorPtr);
#endif
#ifndef XCreateGC_TCL_DECLARED
#define XCreateGC_TCL_DECLARED
/* 59 */
EXTERN GC		XCreateGC(Display *display, Drawable d,
				unsigned long valuemask, XGCValues *values);
#endif
#ifndef XFreeGC_TCL_DECLARED
#define XFreeGC_TCL_DECLARED
/* 60 */
EXTERN void		XFreeGC(Display *display, GC gc);
#endif
#ifndef XInternAtom_TCL_DECLARED
#define XInternAtom_TCL_DECLARED
/* 61 */
EXTERN Atom		XInternAtom(Display *display,
				_Xconst char *atom_name, Bool only_if_exists);
#endif
#ifndef XSetBackground_TCL_DECLARED
#define XSetBackground_TCL_DECLARED
/* 62 */
EXTERN void		XSetBackground(Display *display, GC gc,
				unsigned long foreground);
#endif
#ifndef XSetForeground_TCL_DECLARED
#define XSetForeground_TCL_DECLARED
/* 63 */
EXTERN void		XSetForeground(Display *display, GC gc,
				unsigned long foreground);
#endif
#ifndef XSetClipMask_TCL_DECLARED
#define XSetClipMask_TCL_DECLARED
/* 64 */
EXTERN void		XSetClipMask(Display *display, GC gc, Pixmap pixmap);
#endif
#ifndef XSetClipOrigin_TCL_DECLARED
#define XSetClipOrigin_TCL_DECLARED
/* 65 */
EXTERN void		XSetClipOrigin(Display *display, GC gc,
				int clip_x_origin, int clip_y_origin);
#endif
#ifndef XSetTSOrigin_TCL_DECLARED
#define XSetTSOrigin_TCL_DECLARED
/* 66 */
EXTERN void		XSetTSOrigin(Display *display, GC gc,
				int ts_x_origin, int ts_y_origin);
#endif
#ifndef XChangeGC_TCL_DECLARED
#define XChangeGC_TCL_DECLARED
/* 67 */
EXTERN void		XChangeGC(Display *d, GC gc, unsigned long mask,
				XGCValues *values);
#endif
#ifndef XSetFont_TCL_DECLARED
#define XSetFont_TCL_DECLARED
/* 68 */
EXTERN void		XSetFont(Display *display, GC gc, Font font);
#endif
#ifndef XSetArcMode_TCL_DECLARED
#define XSetArcMode_TCL_DECLARED
/* 69 */
EXTERN void		XSetArcMode(Display *display, GC gc, int arc_mode);
#endif
#ifndef XSetStipple_TCL_DECLARED
#define XSetStipple_TCL_DECLARED
/* 70 */
EXTERN void		XSetStipple(Display *display, GC gc, Pixmap stipple);
#endif
#ifndef XSetFillRule_TCL_DECLARED
#define XSetFillRule_TCL_DECLARED
/* 71 */
EXTERN void		XSetFillRule(Display *display, GC gc, int fill_rule);
#endif
#ifndef XSetFillStyle_TCL_DECLARED
#define XSetFillStyle_TCL_DECLARED
/* 72 */
EXTERN void		XSetFillStyle(Display *display, GC gc,
				int fill_style);
#endif
#ifndef XSetFunction_TCL_DECLARED
#define XSetFunction_TCL_DECLARED
/* 73 */
EXTERN void		XSetFunction(Display *display, GC gc, int function);
#endif
#ifndef XSetLineAttributes_TCL_DECLARED
#define XSetLineAttributes_TCL_DECLARED
/* 74 */
EXTERN void		XSetLineAttributes(Display *display, GC gc,
				unsigned int line_width, int line_style,
				int cap_style, int join_style);
#endif
#ifndef _XInitImageFuncPtrs_TCL_DECLARED
#define _XInitImageFuncPtrs_TCL_DECLARED
/* 75 */
EXTERN int		_XInitImageFuncPtrs(XImage *image);
#endif
#ifndef XCreateIC_TCL_DECLARED
#define XCreateIC_TCL_DECLARED
/* 76 */
EXTERN XIC		XCreateIC(void);
#endif
#ifndef XGetVisualInfo_TCL_DECLARED
#define XGetVisualInfo_TCL_DECLARED
/* 77 */
EXTERN XVisualInfo *	XGetVisualInfo(Display *display, long vinfo_mask,
				XVisualInfo *vinfo_template,
				int *nitems_return);
#endif
#ifndef XSetWMClientMachine_TCL_DECLARED
#define XSetWMClientMachine_TCL_DECLARED
/* 78 */
EXTERN void		XSetWMClientMachine(Display *display, Window w,
				XTextProperty *text_prop);
#endif
#ifndef XStringListToTextProperty_TCL_DECLARED
#define XStringListToTextProperty_TCL_DECLARED
/* 79 */
EXTERN Status		XStringListToTextProperty(char **list, int count,
				XTextProperty *text_prop_return);
#endif
#ifndef XDrawSegments_TCL_DECLARED
#define XDrawSegments_TCL_DECLARED
/* 80 */
EXTERN void		XDrawSegments(Display *display, Drawable d, GC gc,
				XSegment *segments, int nsegments);
#endif
#ifndef XForceScreenSaver_TCL_DECLARED
#define XForceScreenSaver_TCL_DECLARED
/* 81 */
EXTERN void		XForceScreenSaver(Display *display, int mode);
#endif
#ifndef XDrawLine_TCL_DECLARED
#define XDrawLine_TCL_DECLARED
/* 82 */
EXTERN void		XDrawLine(Display *d, Drawable dr, GC g, int x1,
				int y1, int x2, int y2);
#endif
#ifndef XFillRectangle_TCL_DECLARED
#define XFillRectangle_TCL_DECLARED
/* 83 */
EXTERN void		XFillRectangle(Display *display, Drawable d, GC gc,
				int x, int y, unsigned int width,
				unsigned int height);
#endif
#ifndef XClearWindow_TCL_DECLARED
#define XClearWindow_TCL_DECLARED
/* 84 */
EXTERN void		XClearWindow(Display *d, Window w);
#endif
#ifndef XDrawPoint_TCL_DECLARED
#define XDrawPoint_TCL_DECLARED
/* 85 */
EXTERN void		XDrawPoint(Display *display, Drawable d, GC gc,
				int x, int y);
#endif
#ifndef XDrawPoints_TCL_DECLARED
#define XDrawPoints_TCL_DECLARED
/* 86 */
EXTERN void		XDrawPoints(Display *display, Drawable d, GC gc,
				XPoint *points, int npoints, int mode);
#endif
#ifndef XWarpPointer_TCL_DECLARED
#define XWarpPointer_TCL_DECLARED
/* 87 */
EXTERN void		XWarpPointer(Display *display, Window src_w,
				Window dest_w, int src_x, int src_y,
				unsigned int src_width,
				unsigned int src_height, int dest_x,
				int dest_y);
#endif
#ifndef XQueryColor_TCL_DECLARED
#define XQueryColor_TCL_DECLARED
/* 88 */
EXTERN void		XQueryColor(Display *display, Colormap colormap,
				XColor *def_in_out);
#endif
#ifndef XQueryColors_TCL_DECLARED
#define XQueryColors_TCL_DECLARED
/* 89 */
EXTERN void		XQueryColors(Display *display, Colormap colormap,
				XColor *defs_in_out, int ncolors);
#endif
#ifndef XQueryTree_TCL_DECLARED
#define XQueryTree_TCL_DECLARED
/* 90 */
EXTERN Status		XQueryTree(Display *d, Window w1, Window *w2,
				Window *w3, Window **w4, unsigned int *ui);
#endif
#ifndef XSync_TCL_DECLARED
#define XSync_TCL_DECLARED
/* 91 */
EXTERN int		XSync(Display *display, Bool flag);
#endif
#endif /* AQUA */

typedef struct TkIntXlibStubs {
    int magic;
    struct TkIntXlibStubHooks *hooks;

#ifdef __WIN32__ /* WIN */
    void (*xSetDashes) (Display *display, GC gc, int dash_offset, _Xconst char *dash_list, int n); /* 0 */
    XModifierKeymap * (*xGetModifierMapping) (Display *d); /* 1 */
    XImage * (*xCreateImage) (Display *d, Visual *v, unsigned int ui1, int i1, int i2, char *cp, unsigned int ui2, unsigned int ui3, int i3, int i4); /* 2 */
    XImage * (*xGetImage) (Display *d, Drawable dr, int i1, int i2, unsigned int ui1, unsigned int ui2, unsigned long ul, int i3); /* 3 */
    char * (*xGetAtomName) (Display *d, Atom a); /* 4 */
    char * (*xKeysymToString) (KeySym k); /* 5 */
    Colormap (*xCreateColormap) (Display *d, Window w, Visual *v, int i); /* 6 */
    Cursor (*xCreatePixmapCursor) (Display *d, Pixmap p1, Pixmap p2, XColor *x1, XColor *x2, unsigned int ui1, unsigned int ui2); /* 7 */
    Cursor (*xCreateGlyphCursor) (Display *d, Font f1, Font f2, unsigned int ui1, unsigned int ui2, XColor *x1, XColor *x2); /* 8 */
    GContext (*xGContextFromGC) (GC g); /* 9 */
    XHostAddress * (*xListHosts) (Display *d, int *i, Bool *b); /* 10 */
    KeySym (*xKeycodeToKeysym) (Display *d, unsigned int k, int i); /* 11 */
    KeySym (*xStringToKeysym) (_Xconst char *c); /* 12 */
    Window (*xRootWindow) (Display *d, int i); /* 13 */
    XErrorHandler (*xSetErrorHandler) (XErrorHandler x); /* 14 */
    Status (*xIconifyWindow) (Display *d, Window w, int i); /* 15 */
    Status (*xWithdrawWindow) (Display *d, Window w, int i); /* 16 */
    Status (*xGetWMColormapWindows) (Display *d, Window w, Window **wpp, int *ip); /* 17 */
    Status (*xAllocColor) (Display *d, Colormap c, XColor *xp); /* 18 */
    void (*xBell) (Display *d, int i); /* 19 */
    void (*xChangeProperty) (Display *d, Window w, Atom a1, Atom a2, int i1, int i2, _Xconst unsigned char *c, int i3); /* 20 */
    void (*xChangeWindowAttributes) (Display *d, Window w, unsigned long ul, XSetWindowAttributes *x); /* 21 */
    void (*xClearWindow) (Display *d, Window w); /* 22 */
    void (*xConfigureWindow) (Display *d, Window w, unsigned int i, XWindowChanges *x); /* 23 */
    void (*xCopyArea) (Display *d, Drawable dr1, Drawable dr2, GC g, int i1, int i2, unsigned int ui1, unsigned int ui2, int i3, int i4); /* 24 */
    void (*xCopyPlane) (Display *d, Drawable dr1, Drawable dr2, GC g, int i1, int i2, unsigned int ui1, unsigned int ui2, int i3, int i4, unsigned long ul); /* 25 */
    Pixmap (*xCreateBitmapFromData) (Display *display, Drawable d, _Xconst char *data, unsigned int width, unsigned int height); /* 26 */
    void (*xDefineCursor) (Display *d, Window w, Cursor c); /* 27 */
    void (*xDeleteProperty) (Display *d, Window w, Atom a); /* 28 */
    void (*xDestroyWindow) (Display *d, Window w); /* 29 */
    void (*xDrawArc) (Display *d, Drawable dr, GC g, int i1, int i2, unsigned int ui1, unsigned int ui2, int i3, int i4); /* 30 */
    void (*xDrawLines) (Display *d, Drawable dr, GC g, XPoint *x, int i1, int i2); /* 31 */
    void (*xDrawRectangle) (Display *d, Drawable dr, GC g, int i1, int i2, unsigned int ui1, unsigned int ui2); /* 32 */
    void (*xFillArc) (Display *d, Drawable dr, GC g, int i1, int i2, unsigned int ui1, unsigned int ui2, int i3, int i4); /* 33 */
    void (*xFillPolygon) (Display *d, Drawable dr, GC g, XPoint *x, int i1, int i2, int i3); /* 34 */
    void (*xFillRectangles) (Display *d, Drawable dr, GC g, XRectangle *x, int i); /* 35 */
    void (*xForceScreenSaver) (Display *d, int i); /* 36 */
    void (*xFreeColormap) (Display *d, Colormap c); /* 37 */
    void (*xFreeColors) (Display *d, Colormap c, unsigned long *ulp, int i, unsigned long ul); /* 38 */
    void (*xFreeCursor) (Display *d, Cursor c); /* 39 */
    void (*xFreeModifiermap) (XModifierKeymap *x); /* 40 */
    Status (*xGetGeometry) (Display *d, Drawable dr, Window *w, int *i1, int *i2, unsigned int *ui1, unsigned int *ui2, unsigned int *ui3, unsigned int *ui4); /* 41 */
    void (*xGetInputFocus) (Display *d, Window *w, int *i); /* 42 */
    int (*xGetWindowProperty) (Display *d, Window w, Atom a1, long l1, long l2, Bool b, Atom a2, Atom *ap, int *ip, unsigned long *ulp1, unsigned long *ulp2, unsigned char **cpp); /* 43 */
    Status (*xGetWindowAttributes) (Display *d, Window w, XWindowAttributes *x); /* 44 */
    int (*xGrabKeyboard) (Display *d, Window w, Bool b, int i1, int i2, Time t); /* 45 */
    int (*xGrabPointer) (Display *d, Window w1, Bool b, unsigned int ui, int i1, int i2, Window w2, Cursor c, Time t); /* 46 */
    KeyCode (*xKeysymToKeycode) (Display *d, KeySym k); /* 47 */
    Status (*xLookupColor) (Display *d, Colormap c1, _Xconst char *c2, XColor *x1, XColor *x2); /* 48 */
    void (*xMapWindow) (Display *d, Window w); /* 49 */
    void (*xMoveResizeWindow) (Display *d, Window w, int i1, int i2, unsigned int ui1, unsigned int ui2); /* 50 */
    void (*xMoveWindow) (Display *d, Window w, int i1, int i2); /* 51 */
    void (*xNextEvent) (Display *d, XEvent *x); /* 52 */
    void (*xPutBackEvent) (Display *d, XEvent *x); /* 53 */
    void (*xQueryColors) (Display *d, Colormap c, XColor *x, int i); /* 54 */
    Bool (*xQueryPointer) (Display *d, Window w1, Window *w2, Window *w3, int *i1, int *i2, int *i3, int *i4, unsigned int *ui); /* 55 */
    Status (*xQueryTree) (Display *d, Window w1, Window *w2, Window *w3, Window **w4, unsigned int *ui); /* 56 */
    void (*xRaiseWindow) (Display *d, Window w); /* 57 */
    void (*xRefreshKeyboardMapping) (XMappingEvent *x); /* 58 */
    void (*xResizeWindow) (Display *d, Window w, unsigned int ui1, unsigned int ui2); /* 59 */
    void (*xSelectInput) (Display *d, Window w, long l); /* 60 */
    Status (*xSendEvent) (Display *d, Window w, Bool b, long l, XEvent *x); /* 61 */
    void (*xSetCommand) (Display *d, Window w, CONST char **c, int i); /* 62 */
    void (*xSetIconName) (Display *d, Window w, _Xconst char *c); /* 63 */
    void (*xSetInputFocus) (Display *d, Window w, int i, Time t); /* 64 */
    void (*xSetSelectionOwner) (Display *d, Atom a, Window w, Time t); /* 65 */
    void (*xSetWindowBackground) (Display *d, Window w, unsigned long ul); /* 66 */
    void (*xSetWindowBackgroundPixmap) (Display *d, Window w, Pixmap p); /* 67 */
    void (*xSetWindowBorder) (Display *d, Window w, unsigned long ul); /* 68 */
    void (*xSetWindowBorderPixmap) (Display *d, Window w, Pixmap p); /* 69 */
    void (*xSetWindowBorderWidth) (Display *d, Window w, unsigned int ui); /* 70 */
    void (*xSetWindowColormap) (Display *d, Window w, Colormap c); /* 71 */
    Bool (*xTranslateCoordinates) (Display *d, Window w1, Window w2, int i1, int i2, int *i3, int *i4, Window *w3); /* 72 */
    void (*xUngrabKeyboard) (Display *d, Time t); /* 73 */
    void (*xUngrabPointer) (Display *d, Time t); /* 74 */
    void (*xUnmapWindow) (Display *d, Window w); /* 75 */
    void (*xWindowEvent) (Display *d, Window w, long l, XEvent *x); /* 76 */
    void (*xDestroyIC) (XIC x); /* 77 */
    Bool (*xFilterEvent) (XEvent *x, Window w); /* 78 */
    int (*xmbLookupString) (XIC xi, XKeyPressedEvent *xk, char *c, int i, KeySym *k, Status *s); /* 79 */
    void (*tkPutImage) (unsigned long *colors, int ncolors, Display *display, Drawable d, GC gc, XImage *image, int src_x, int src_y, int dest_x, int dest_y, unsigned int width, unsigned int height); /* 80 */
    void *reserved81;
    Status (*xParseColor) (Display *display, Colormap map, _Xconst char *spec, XColor *colorPtr); /* 82 */
    GC (*xCreateGC) (Display *display, Drawable d, unsigned long valuemask, XGCValues *values); /* 83 */
    void (*xFreeGC) (Display *display, GC gc); /* 84 */
    Atom (*xInternAtom) (Display *display, _Xconst char *atom_name, Bool only_if_exists); /* 85 */
    void (*xSetBackground) (Display *display, GC gc, unsigned long foreground); /* 86 */
    void (*xSetForeground) (Display *display, GC gc, unsigned long foreground); /* 87 */
    void (*xSetClipMask) (Display *display, GC gc, Pixmap pixmap); /* 88 */
    void (*xSetClipOrigin) (Display *display, GC gc, int clip_x_origin, int clip_y_origin); /* 89 */
    void (*xSetTSOrigin) (Display *display, GC gc, int ts_x_origin, int ts_y_origin); /* 90 */
    void (*xChangeGC) (Display *d, GC gc, unsigned long mask, XGCValues *values); /* 91 */
    void (*xSetFont) (Display *display, GC gc, Font font); /* 92 */
    void (*xSetArcMode) (Display *display, GC gc, int arc_mode); /* 93 */
    void (*xSetStipple) (Display *display, GC gc, Pixmap stipple); /* 94 */
    void (*xSetFillRule) (Display *display, GC gc, int fill_rule); /* 95 */
    void (*xSetFillStyle) (Display *display, GC gc, int fill_style); /* 96 */
    void (*xSetFunction) (Display *display, GC gc, int function); /* 97 */
    void (*xSetLineAttributes) (Display *display, GC gc, unsigned int line_width, int line_style, int cap_style, int join_style); /* 98 */
    int (*_XInitImageFuncPtrs) (XImage *image); /* 99 */
    XIC (*xCreateIC) (void); /* 100 */
    XVisualInfo * (*xGetVisualInfo) (Display *display, long vinfo_mask, XVisualInfo *vinfo_template, int *nitems_return); /* 101 */
    void (*xSetWMClientMachine) (Display *display, Window w, XTextProperty *text_prop); /* 102 */
    Status (*xStringListToTextProperty) (char **list, int count, XTextProperty *text_prop_return); /* 103 */
    void (*xDrawLine) (Display *d, Drawable dr, GC g, int x1, int y1, int x2, int y2); /* 104 */
    void (*xWarpPointer) (Display *d, Window s, Window dw, int sx, int sy, unsigned int sw, unsigned int sh, int dx, int dy); /* 105 */
    void (*xFillRectangle) (Display *display, Drawable d, GC gc, int x, int y, unsigned int width, unsigned int height); /* 106 */
#endif /* WIN */
#ifdef MAC_OSX_TK /* AQUA */
    void (*xSetDashes) (Display *display, GC gc, int dash_offset, _Xconst char *dash_list, int n); /* 0 */
    XModifierKeymap * (*xGetModifierMapping) (Display *d); /* 1 */
    XImage * (*xCreateImage) (Display *d, Visual *v, unsigned int ui1, int i1, int i2, char *cp, unsigned int ui2, unsigned int ui3, int i3, int i4); /* 2 */
    XImage * (*xGetImage) (Display *d, Drawable dr, int i1, int i2, unsigned int ui1, unsigned int ui2, unsigned long ul, int i3); /* 3 */
    char * (*xGetAtomName) (Display *d, Atom a); /* 4 */
    char * (*xKeysymToString) (KeySym k); /* 5 */
    Colormap (*xCreateColormap) (Display *d, Window w, Visual *v, int i); /* 6 */
    GContext (*xGContextFromGC) (GC g); /* 7 */
    KeySym (*xKeycodeToKeysym) (Display *d, KeyCode k, int i); /* 8 */
    KeySym (*xStringToKeysym) (_Xconst char *c); /* 9 */
    Window (*xRootWindow) (Display *d, int i); /* 10 */
    XErrorHandler (*xSetErrorHandler) (XErrorHandler x); /* 11 */
    Status (*xAllocColor) (Display *d, Colormap c, XColor *xp); /* 12 */
    void (*xBell) (Display *d, int i); /* 13 */
    void (*xChangeProperty) (Display *d, Window w, Atom a1, Atom a2, int i1, int i2, _Xconst unsigned char *c, int i3); /* 14 */
    void (*xChangeWindowAttributes) (Display *d, Window w, unsigned long ul, XSetWindowAttributes *x); /* 15 */
    void (*xConfigureWindow) (Display *d, Window w, unsigned int i, XWindowChanges *x); /* 16 */
    void (*xCopyArea) (Display *d, Drawable dr1, Drawable dr2, GC g, int i1, int i2, unsigned int ui1, unsigned int ui2, int i3, int i4); /* 17 */
    void (*xCopyPlane) (Display *d, Drawable dr1, Drawable dr2, GC g, int i1, int i2, unsigned int ui1, unsigned int ui2, int i3, int i4, unsigned long ul); /* 18 */
    Pixmap (*xCreateBitmapFromData) (Display *display, Drawable d, _Xconst char *data, unsigned int width, unsigned int height); /* 19 */
    void (*xDefineCursor) (Display *d, Window w, Cursor c); /* 20 */
    void (*xDestroyWindow) (Display *d, Window w); /* 21 */
    void (*xDrawArc) (Display *d, Drawable dr, GC g, int i1, int i2, unsigned int ui1, unsigned int ui2, int i3, int i4); /* 22 */
    void (*xDrawLines) (Display *d, Drawable dr, GC g, XPoint *x, int i1, int i2); /* 23 */
    void (*xDrawRectangle) (Display *d, Drawable dr, GC g, int i1, int i2, unsigned int ui1, unsigned int ui2); /* 24 */
    void (*xFillArc) (Display *d, Drawable dr, GC g, int i1, int i2, unsigned int ui1, unsigned int ui2, int i3, int i4); /* 25 */
    void (*xFillPolygon) (Display *d, Drawable dr, GC g, XPoint *x, int i1, int i2, int i3); /* 26 */
    void (*xFillRectangles) (Display *d, Drawable dr, GC g, XRectangle *x, int i); /* 27 */
    void (*xFreeColormap) (Display *d, Colormap c); /* 28 */
    void (*xFreeColors) (Display *d, Colormap c, unsigned long *ulp, int i, unsigned long ul); /* 29 */
    void (*xFreeModifiermap) (XModifierKeymap *x); /* 30 */
    Status (*xGetGeometry) (Display *d, Drawable dr, Window *w, int *i1, int *i2, unsigned int *ui1, unsigned int *ui2, unsigned int *ui3, unsigned int *ui4); /* 31 */
    int (*xGetWindowProperty) (Display *d, Window w, Atom a1, long l1, long l2, Bool b, Atom a2, Atom *ap, int *ip, unsigned long *ulp1, unsigned long *ulp2, unsigned char **cpp); /* 32 */
    int (*xGrabKeyboard) (Display *d, Window w, Bool b, int i1, int i2, Time t); /* 33 */
    int (*xGrabPointer) (Display *d, Window w1, Bool b, unsigned int ui, int i1, int i2, Window w2, Cursor c, Time t); /* 34 */
    KeyCode (*xKeysymToKeycode) (Display *d, KeySym k); /* 35 */
    void (*xMapWindow) (Display *d, Window w); /* 36 */
    void (*xMoveResizeWindow) (Display *d, Window w, int i1, int i2, unsigned int ui1, unsigned int ui2); /* 37 */
    void (*xMoveWindow) (Display *d, Window w, int i1, int i2); /* 38 */
    Bool (*xQueryPointer) (Display *d, Window w1, Window *w2, Window *w3, int *i1, int *i2, int *i3, int *i4, unsigned int *ui); /* 39 */
    void (*xRaiseWindow) (Display *d, Window w); /* 40 */
    void (*xRefreshKeyboardMapping) (XMappingEvent *x); /* 41 */
    void (*xResizeWindow) (Display *d, Window w, unsigned int ui1, unsigned int ui2); /* 42 */
    void (*xSelectInput) (Display *d, Window w, long l); /* 43 */
    Status (*xSendEvent) (Display *d, Window w, Bool b, long l, XEvent *x); /* 44 */
    void (*xSetIconName) (Display *d, Window w, _Xconst char *c); /* 45 */
    void (*xSetInputFocus) (Display *d, Window w, int i, Time t); /* 46 */
    void (*xSetSelectionOwner) (Display *d, Atom a, Window w, Time t); /* 47 */
    void (*xSetWindowBackground) (Display *d, Window w, unsigned long ul); /* 48 */
    void (*xSetWindowBackgroundPixmap) (Display *d, Window w, Pixmap p); /* 49 */
    void (*xSetWindowBorder) (Display *d, Window w, unsigned long ul); /* 50 */
    void (*xSetWindowBorderPixmap) (Display *d, Window w, Pixmap p); /* 51 */
    void (*xSetWindowBorderWidth) (Display *d, Window w, unsigned int ui); /* 52 */
    void (*xSetWindowColormap) (Display *d, Window w, Colormap c); /* 53 */
    void (*xUngrabKeyboard) (Display *d, Time t); /* 54 */
    void (*xUngrabPointer) (Display *d, Time t); /* 55 */
    void (*xUnmapWindow) (Display *d, Window w); /* 56 */
    void (*tkPutImage) (unsigned long *colors, int ncolors, Display *display, Drawable d, GC gc, XImage *image, int src_x, int src_y, int dest_x, int dest_y, unsigned int width, unsigned int height); /* 57 */
    Status (*xParseColor) (Display *display, Colormap map, _Xconst char *spec, XColor *colorPtr); /* 58 */
    GC (*xCreateGC) (Display *display, Drawable d, unsigned long valuemask, XGCValues *values); /* 59 */
    void (*xFreeGC) (Display *display, GC gc); /* 60 */
    Atom (*xInternAtom) (Display *display, _Xconst char *atom_name, Bool only_if_exists); /* 61 */
    void (*xSetBackground) (Display *display, GC gc, unsigned long foreground); /* 62 */
    void (*xSetForeground) (Display *display, GC gc, unsigned long foreground); /* 63 */
    void (*xSetClipMask) (Display *display, GC gc, Pixmap pixmap); /* 64 */
    void (*xSetClipOrigin) (Display *display, GC gc, int clip_x_origin, int clip_y_origin); /* 65 */
    void (*xSetTSOrigin) (Display *display, GC gc, int ts_x_origin, int ts_y_origin); /* 66 */
    void (*xChangeGC) (Display *d, GC gc, unsigned long mask, XGCValues *values); /* 67 */
    void (*xSetFont) (Display *display, GC gc, Font font); /* 68 */
    void (*xSetArcMode) (Display *display, GC gc, int arc_mode); /* 69 */
    void (*xSetStipple) (Display *display, GC gc, Pixmap stipple); /* 70 */
    void (*xSetFillRule) (Display *display, GC gc, int fill_rule); /* 71 */
    void (*xSetFillStyle) (Display *display, GC gc, int fill_style); /* 72 */
    void (*xSetFunction) (Display *display, GC gc, int function); /* 73 */
    void (*xSetLineAttributes) (Display *display, GC gc, unsigned int line_width, int line_style, int cap_style, int join_style); /* 74 */
    int (*_XInitImageFuncPtrs) (XImage *image); /* 75 */
    XIC (*xCreateIC) (void); /* 76 */
    XVisualInfo * (*xGetVisualInfo) (Display *display, long vinfo_mask, XVisualInfo *vinfo_template, int *nitems_return); /* 77 */
    void (*xSetWMClientMachine) (Display *display, Window w, XTextProperty *text_prop); /* 78 */
    Status (*xStringListToTextProperty) (char **list, int count, XTextProperty *text_prop_return); /* 79 */
    void (*xDrawSegments) (Display *display, Drawable d, GC gc, XSegment *segments, int nsegments); /* 80 */
    void (*xForceScreenSaver) (Display *display, int mode); /* 81 */
    void (*xDrawLine) (Display *d, Drawable dr, GC g, int x1, int y1, int x2, int y2); /* 82 */
    void (*xFillRectangle) (Display *display, Drawable d, GC gc, int x, int y, unsigned int width, unsigned int height); /* 83 */
    void (*xClearWindow) (Display *d, Window w); /* 84 */
    void (*xDrawPoint) (Display *display, Drawable d, GC gc, int x, int y); /* 85 */
    void (*xDrawPoints) (Display *display, Drawable d, GC gc, XPoint *points, int npoints, int mode); /* 86 */
    void (*xWarpPointer) (Display *display, Window src_w, Window dest_w, int src_x, int src_y, unsigned int src_width, unsigned int src_height, int dest_x, int dest_y); /* 87 */
    void (*xQueryColor) (Display *display, Colormap colormap, XColor *def_in_out); /* 88 */
    void (*xQueryColors) (Display *display, Colormap colormap, XColor *defs_in_out, int ncolors); /* 89 */
    Status (*xQueryTree) (Display *d, Window w1, Window *w2, Window *w3, Window **w4, unsigned int *ui); /* 90 */
    int (*xSync) (Display *display, Bool flag); /* 91 */
#endif /* AQUA */
} TkIntXlibStubs;

#ifdef __cplusplus
extern "C" {
#endif
extern TkIntXlibStubs *tkIntXlibStubsPtr;
#ifdef __cplusplus
}
#endif

#if defined(USE_TK_STUBS) && !defined(USE_TK_STUB_PROCS)

/*
 * Inline function declarations:
 */

#ifdef __WIN32__ /* WIN */
#ifndef XSetDashes
#define XSetDashes \
	(tkIntXlibStubsPtr->xSetDashes) /* 0 */
#endif
#ifndef XGetModifierMapping
#define XGetModifierMapping \
	(tkIntXlibStubsPtr->xGetModifierMapping) /* 1 */
#endif
#ifndef XCreateImage
#define XCreateImage \
	(tkIntXlibStubsPtr->xCreateImage) /* 2 */
#endif
#ifndef XGetImage
#define XGetImage \
	(tkIntXlibStubsPtr->xGetImage) /* 3 */
#endif
#ifndef XGetAtomName
#define XGetAtomName \
	(tkIntXlibStubsPtr->xGetAtomName) /* 4 */
#endif
#ifndef XKeysymToString
#define XKeysymToString \
	(tkIntXlibStubsPtr->xKeysymToString) /* 5 */
#endif
#ifndef XCreateColormap
#define XCreateColormap \
	(tkIntXlibStubsPtr->xCreateColormap) /* 6 */
#endif
#ifndef XCreatePixmapCursor
#define XCreatePixmapCursor \
	(tkIntXlibStubsPtr->xCreatePixmapCursor) /* 7 */
#endif
#ifndef XCreateGlyphCursor
#define XCreateGlyphCursor \
	(tkIntXlibStubsPtr->xCreateGlyphCursor) /* 8 */
#endif
#ifndef XGContextFromGC
#define XGContextFromGC \
	(tkIntXlibStubsPtr->xGContextFromGC) /* 9 */
#endif
#ifndef XListHosts
#define XListHosts \
	(tkIntXlibStubsPtr->xListHosts) /* 10 */
#endif
#ifndef XKeycodeToKeysym
#define XKeycodeToKeysym \
	(tkIntXlibStubsPtr->xKeycodeToKeysym) /* 11 */
#endif
#ifndef XStringToKeysym
#define XStringToKeysym \
	(tkIntXlibStubsPtr->xStringToKeysym) /* 12 */
#endif
#ifndef XRootWindow
#define XRootWindow \
	(tkIntXlibStubsPtr->xRootWindow) /* 13 */
#endif
#ifndef XSetErrorHandler
#define XSetErrorHandler \
	(tkIntXlibStubsPtr->xSetErrorHandler) /* 14 */
#endif
#ifndef XIconifyWindow
#define XIconifyWindow \
	(tkIntXlibStubsPtr->xIconifyWindow) /* 15 */
#endif
#ifndef XWithdrawWindow
#define XWithdrawWindow \
	(tkIntXlibStubsPtr->xWithdrawWindow) /* 16 */
#endif
#ifndef XGetWMColormapWindows
#define XGetWMColormapWindows \
	(tkIntXlibStubsPtr->xGetWMColormapWindows) /* 17 */
#endif
#ifndef XAllocColor
#define XAllocColor \
	(tkIntXlibStubsPtr->xAllocColor) /* 18 */
#endif
#ifndef XBell
#define XBell \
	(tkIntXlibStubsPtr->xBell) /* 19 */
#endif
#ifndef XChangeProperty
#define XChangeProperty \
	(tkIntXlibStubsPtr->xChangeProperty) /* 20 */
#endif
#ifndef XChangeWindowAttributes
#define XChangeWindowAttributes \
	(tkIntXlibStubsPtr->xChangeWindowAttributes) /* 21 */
#endif
#ifndef XClearWindow
#define XClearWindow \
	(tkIntXlibStubsPtr->xClearWindow) /* 22 */
#endif
#ifndef XConfigureWindow
#define XConfigureWindow \
	(tkIntXlibStubsPtr->xConfigureWindow) /* 23 */
#endif
#ifndef XCopyArea
#define XCopyArea \
	(tkIntXlibStubsPtr->xCopyArea) /* 24 */
#endif
#ifndef XCopyPlane
#define XCopyPlane \
	(tkIntXlibStubsPtr->xCopyPlane) /* 25 */
#endif
#ifndef XCreateBitmapFromData
#define XCreateBitmapFromData \
	(tkIntXlibStubsPtr->xCreateBitmapFromData) /* 26 */
#endif
#ifndef XDefineCursor
#define XDefineCursor \
	(tkIntXlibStubsPtr->xDefineCursor) /* 27 */
#endif
#ifndef XDeleteProperty
#define XDeleteProperty \
	(tkIntXlibStubsPtr->xDeleteProperty) /* 28 */
#endif
#ifndef XDestroyWindow
#define XDestroyWindow \
	(tkIntXlibStubsPtr->xDestroyWindow) /* 29 */
#endif
#ifndef XDrawArc
#define XDrawArc \
	(tkIntXlibStubsPtr->xDrawArc) /* 30 */
#endif
#ifndef XDrawLines
#define XDrawLines \
	(tkIntXlibStubsPtr->xDrawLines) /* 31 */
#endif
#ifndef XDrawRectangle
#define XDrawRectangle \
	(tkIntXlibStubsPtr->xDrawRectangle) /* 32 */
#endif
#ifndef XFillArc
#define XFillArc \
	(tkIntXlibStubsPtr->xFillArc) /* 33 */
#endif
#ifndef XFillPolygon
#define XFillPolygon \
	(tkIntXlibStubsPtr->xFillPolygon) /* 34 */
#endif
#ifndef XFillRectangles
#define XFillRectangles \
	(tkIntXlibStubsPtr->xFillRectangles) /* 35 */
#endif
#ifndef XForceScreenSaver
#define XForceScreenSaver \
	(tkIntXlibStubsPtr->xForceScreenSaver) /* 36 */
#endif
#ifndef XFreeColormap
#define XFreeColormap \
	(tkIntXlibStubsPtr->xFreeColormap) /* 37 */
#endif
#ifndef XFreeColors
#define XFreeColors \
	(tkIntXlibStubsPtr->xFreeColors) /* 38 */
#endif
#ifndef XFreeCursor
#define XFreeCursor \
	(tkIntXlibStubsPtr->xFreeCursor) /* 39 */
#endif
#ifndef XFreeModifiermap
#define XFreeModifiermap \
	(tkIntXlibStubsPtr->xFreeModifiermap) /* 40 */
#endif
#ifndef XGetGeometry
#define XGetGeometry \
	(tkIntXlibStubsPtr->xGetGeometry) /* 41 */
#endif
#ifndef XGetInputFocus
#define XGetInputFocus \
	(tkIntXlibStubsPtr->xGetInputFocus) /* 42 */
#endif
#ifndef XGetWindowProperty
#define XGetWindowProperty \
	(tkIntXlibStubsPtr->xGetWindowProperty) /* 43 */
#endif
#ifndef XGetWindowAttributes
#define XGetWindowAttributes \
	(tkIntXlibStubsPtr->xGetWindowAttributes) /* 44 */
#endif
#ifndef XGrabKeyboard
#define XGrabKeyboard \
	(tkIntXlibStubsPtr->xGrabKeyboard) /* 45 */
#endif
#ifndef XGrabPointer
#define XGrabPointer \
	(tkIntXlibStubsPtr->xGrabPointer) /* 46 */
#endif
#ifndef XKeysymToKeycode
#define XKeysymToKeycode \
	(tkIntXlibStubsPtr->xKeysymToKeycode) /* 47 */
#endif
#ifndef XLookupColor
#define XLookupColor \
	(tkIntXlibStubsPtr->xLookupColor) /* 48 */
#endif
#ifndef XMapWindow
#define XMapWindow \
	(tkIntXlibStubsPtr->xMapWindow) /* 49 */
#endif
#ifndef XMoveResizeWindow
#define XMoveResizeWindow \
	(tkIntXlibStubsPtr->xMoveResizeWindow) /* 50 */
#endif
#ifndef XMoveWindow
#define XMoveWindow \
	(tkIntXlibStubsPtr->xMoveWindow) /* 51 */
#endif
#ifndef XNextEvent
#define XNextEvent \
	(tkIntXlibStubsPtr->xNextEvent) /* 52 */
#endif
#ifndef XPutBackEvent
#define XPutBackEvent \
	(tkIntXlibStubsPtr->xPutBackEvent) /* 53 */
#endif
#ifndef XQueryColors
#define XQueryColors \
	(tkIntXlibStubsPtr->xQueryColors) /* 54 */
#endif
#ifndef XQueryPointer
#define XQueryPointer \
	(tkIntXlibStubsPtr->xQueryPointer) /* 55 */
#endif
#ifndef XQueryTree
#define XQueryTree \
	(tkIntXlibStubsPtr->xQueryTree) /* 56 */
#endif
#ifndef XRaiseWindow
#define XRaiseWindow \
	(tkIntXlibStubsPtr->xRaiseWindow) /* 57 */
#endif
#ifndef XRefreshKeyboardMapping
#define XRefreshKeyboardMapping \
	(tkIntXlibStubsPtr->xRefreshKeyboardMapping) /* 58 */
#endif
#ifndef XResizeWindow
#define XResizeWindow \
	(tkIntXlibStubsPtr->xResizeWindow) /* 59 */
#endif
#ifndef XSelectInput
#define XSelectInput \
	(tkIntXlibStubsPtr->xSelectInput) /* 60 */
#endif
#ifndef XSendEvent
#define XSendEvent \
	(tkIntXlibStubsPtr->xSendEvent) /* 61 */
#endif
#ifndef XSetCommand
#define XSetCommand \
	(tkIntXlibStubsPtr->xSetCommand) /* 62 */
#endif
#ifndef XSetIconName
#define XSetIconName \
	(tkIntXlibStubsPtr->xSetIconName) /* 63 */
#endif
#ifndef XSetInputFocus
#define XSetInputFocus \
	(tkIntXlibStubsPtr->xSetInputFocus) /* 64 */
#endif
#ifndef XSetSelectionOwner
#define XSetSelectionOwner \
	(tkIntXlibStubsPtr->xSetSelectionOwner) /* 65 */
#endif
#ifndef XSetWindowBackground
#define XSetWindowBackground \
	(tkIntXlibStubsPtr->xSetWindowBackground) /* 66 */
#endif
#ifndef XSetWindowBackgroundPixmap
#define XSetWindowBackgroundPixmap \
	(tkIntXlibStubsPtr->xSetWindowBackgroundPixmap) /* 67 */
#endif
#ifndef XSetWindowBorder
#define XSetWindowBorder \
	(tkIntXlibStubsPtr->xSetWindowBorder) /* 68 */
#endif
#ifndef XSetWindowBorderPixmap
#define XSetWindowBorderPixmap \
	(tkIntXlibStubsPtr->xSetWindowBorderPixmap) /* 69 */
#endif
#ifndef XSetWindowBorderWidth
#define XSetWindowBorderWidth \
	(tkIntXlibStubsPtr->xSetWindowBorderWidth) /* 70 */
#endif
#ifndef XSetWindowColormap
#define XSetWindowColormap \
	(tkIntXlibStubsPtr->xSetWindowColormap) /* 71 */
#endif
#ifndef XTranslateCoordinates
#define XTranslateCoordinates \
	(tkIntXlibStubsPtr->xTranslateCoordinates) /* 72 */
#endif
#ifndef XUngrabKeyboard
#define XUngrabKeyboard \
	(tkIntXlibStubsPtr->xUngrabKeyboard) /* 73 */
#endif
#ifndef XUngrabPointer
#define XUngrabPointer \
	(tkIntXlibStubsPtr->xUngrabPointer) /* 74 */
#endif
#ifndef XUnmapWindow
#define XUnmapWindow \
	(tkIntXlibStubsPtr->xUnmapWindow) /* 75 */
#endif
#ifndef XWindowEvent
#define XWindowEvent \
	(tkIntXlibStubsPtr->xWindowEvent) /* 76 */
#endif
#ifndef XDestroyIC
#define XDestroyIC \
	(tkIntXlibStubsPtr->xDestroyIC) /* 77 */
#endif
#ifndef XFilterEvent
#define XFilterEvent \
	(tkIntXlibStubsPtr->xFilterEvent) /* 78 */
#endif
#ifndef XmbLookupString
#define XmbLookupString \
	(tkIntXlibStubsPtr->xmbLookupString) /* 79 */
#endif
#ifndef TkPutImage
#define TkPutImage \
	(tkIntXlibStubsPtr->tkPutImage) /* 80 */
#endif
/* Slot 81 is reserved */
#ifndef XParseColor
#define XParseColor \
	(tkIntXlibStubsPtr->xParseColor) /* 82 */
#endif
#ifndef XCreateGC
#define XCreateGC \
	(tkIntXlibStubsPtr->xCreateGC) /* 83 */
#endif
#ifndef XFreeGC
#define XFreeGC \
	(tkIntXlibStubsPtr->xFreeGC) /* 84 */
#endif
#ifndef XInternAtom
#define XInternAtom \
	(tkIntXlibStubsPtr->xInternAtom) /* 85 */
#endif
#ifndef XSetBackground
#define XSetBackground \
	(tkIntXlibStubsPtr->xSetBackground) /* 86 */
#endif
#ifndef XSetForeground
#define XSetForeground \
	(tkIntXlibStubsPtr->xSetForeground) /* 87 */
#endif
#ifndef XSetClipMask
#define XSetClipMask \
	(tkIntXlibStubsPtr->xSetClipMask) /* 88 */
#endif
#ifndef XSetClipOrigin
#define XSetClipOrigin \
	(tkIntXlibStubsPtr->xSetClipOrigin) /* 89 */
#endif
#ifndef XSetTSOrigin
#define XSetTSOrigin \
	(tkIntXlibStubsPtr->xSetTSOrigin) /* 90 */
#endif
#ifndef XChangeGC
#define XChangeGC \
	(tkIntXlibStubsPtr->xChangeGC) /* 91 */
#endif
#ifndef XSetFont
#define XSetFont \
	(tkIntXlibStubsPtr->xSetFont) /* 92 */
#endif
#ifndef XSetArcMode
#define XSetArcMode \
	(tkIntXlibStubsPtr->xSetArcMode) /* 93 */
#endif
#ifndef XSetStipple
#define XSetStipple \
	(tkIntXlibStubsPtr->xSetStipple) /* 94 */
#endif
#ifndef XSetFillRule
#define XSetFillRule \
	(tkIntXlibStubsPtr->xSetFillRule) /* 95 */
#endif
#ifndef XSetFillStyle
#define XSetFillStyle \
	(tkIntXlibStubsPtr->xSetFillStyle) /* 96 */
#endif
#ifndef XSetFunction
#define XSetFunction \
	(tkIntXlibStubsPtr->xSetFunction) /* 97 */
#endif
#ifndef XSetLineAttributes
#define XSetLineAttributes \
	(tkIntXlibStubsPtr->xSetLineAttributes) /* 98 */
#endif
#ifndef _XInitImageFuncPtrs
#define _XInitImageFuncPtrs \
	(tkIntXlibStubsPtr->_XInitImageFuncPtrs) /* 99 */
#endif
#ifndef XCreateIC
#define XCreateIC \
	(tkIntXlibStubsPtr->xCreateIC) /* 100 */
#endif
#ifndef XGetVisualInfo
#define XGetVisualInfo \
	(tkIntXlibStubsPtr->xGetVisualInfo) /* 101 */
#endif
#ifndef XSetWMClientMachine
#define XSetWMClientMachine \
	(tkIntXlibStubsPtr->xSetWMClientMachine) /* 102 */
#endif
#ifndef XStringListToTextProperty
#define XStringListToTextProperty \
	(tkIntXlibStubsPtr->xStringListToTextProperty) /* 103 */
#endif
#ifndef XDrawLine
#define XDrawLine \
	(tkIntXlibStubsPtr->xDrawLine) /* 104 */
#endif
#ifndef XWarpPointer
#define XWarpPointer \
	(tkIntXlibStubsPtr->xWarpPointer) /* 105 */
#endif
#ifndef XFillRectangle
#define XFillRectangle \
	(tkIntXlibStubsPtr->xFillRectangle) /* 106 */
#endif
#endif /* WIN */
#ifdef MAC_OSX_TK /* AQUA */
#ifndef XSetDashes
#define XSetDashes \
	(tkIntXlibStubsPtr->xSetDashes) /* 0 */
#endif
#ifndef XGetModifierMapping
#define XGetModifierMapping \
	(tkIntXlibStubsPtr->xGetModifierMapping) /* 1 */
#endif
#ifndef XCreateImage
#define XCreateImage \
	(tkIntXlibStubsPtr->xCreateImage) /* 2 */
#endif
#ifndef XGetImage
#define XGetImage \
	(tkIntXlibStubsPtr->xGetImage) /* 3 */
#endif
#ifndef XGetAtomName
#define XGetAtomName \
	(tkIntXlibStubsPtr->xGetAtomName) /* 4 */
#endif
#ifndef XKeysymToString
#define XKeysymToString \
	(tkIntXlibStubsPtr->xKeysymToString) /* 5 */
#endif
#ifndef XCreateColormap
#define XCreateColormap \
	(tkIntXlibStubsPtr->xCreateColormap) /* 6 */
#endif
#ifndef XGContextFromGC
#define XGContextFromGC \
	(tkIntXlibStubsPtr->xGContextFromGC) /* 7 */
#endif
#ifndef XKeycodeToKeysym
#define XKeycodeToKeysym \
	(tkIntXlibStubsPtr->xKeycodeToKeysym) /* 8 */
#endif
#ifndef XStringToKeysym
#define XStringToKeysym \
	(tkIntXlibStubsPtr->xStringToKeysym) /* 9 */
#endif
#ifndef XRootWindow
#define XRootWindow \
	(tkIntXlibStubsPtr->xRootWindow) /* 10 */
#endif
#ifndef XSetErrorHandler
#define XSetErrorHandler \
	(tkIntXlibStubsPtr->xSetErrorHandler) /* 11 */
#endif
#ifndef XAllocColor
#define XAllocColor \
	(tkIntXlibStubsPtr->xAllocColor) /* 12 */
#endif
#ifndef XBell
#define XBell \
	(tkIntXlibStubsPtr->xBell) /* 13 */
#endif
#ifndef XChangeProperty
#define XChangeProperty \
	(tkIntXlibStubsPtr->xChangeProperty) /* 14 */
#endif
#ifndef XChangeWindowAttributes
#define XChangeWindowAttributes \
	(tkIntXlibStubsPtr->xChangeWindowAttributes) /* 15 */
#endif
#ifndef XConfigureWindow
#define XConfigureWindow \
	(tkIntXlibStubsPtr->xConfigureWindow) /* 16 */
#endif
#ifndef XCopyArea
#define XCopyArea \
	(tkIntXlibStubsPtr->xCopyArea) /* 17 */
#endif
#ifndef XCopyPlane
#define XCopyPlane \
	(tkIntXlibStubsPtr->xCopyPlane) /* 18 */
#endif
#ifndef XCreateBitmapFromData
#define XCreateBitmapFromData \
	(tkIntXlibStubsPtr->xCreateBitmapFromData) /* 19 */
#endif
#ifndef XDefineCursor
#define XDefineCursor \
	(tkIntXlibStubsPtr->xDefineCursor) /* 20 */
#endif
#ifndef XDestroyWindow
#define XDestroyWindow \
	(tkIntXlibStubsPtr->xDestroyWindow) /* 21 */
#endif
#ifndef XDrawArc
#define XDrawArc \
	(tkIntXlibStubsPtr->xDrawArc) /* 22 */
#endif
#ifndef XDrawLines
#define XDrawLines \
	(tkIntXlibStubsPtr->xDrawLines) /* 23 */
#endif
#ifndef XDrawRectangle
#define XDrawRectangle \
	(tkIntXlibStubsPtr->xDrawRectangle) /* 24 */
#endif
#ifndef XFillArc
#define XFillArc \
	(tkIntXlibStubsPtr->xFillArc) /* 25 */
#endif
#ifndef XFillPolygon
#define XFillPolygon \
	(tkIntXlibStubsPtr->xFillPolygon) /* 26 */
#endif
#ifndef XFillRectangles
#define XFillRectangles \
	(tkIntXlibStubsPtr->xFillRectangles) /* 27 */
#endif
#ifndef XFreeColormap
#define XFreeColormap \
	(tkIntXlibStubsPtr->xFreeColormap) /* 28 */
#endif
#ifndef XFreeColors
#define XFreeColors \
	(tkIntXlibStubsPtr->xFreeColors) /* 29 */
#endif
#ifndef XFreeModifiermap
#define XFreeModifiermap \
	(tkIntXlibStubsPtr->xFreeModifiermap) /* 30 */
#endif
#ifndef XGetGeometry
#define XGetGeometry \
	(tkIntXlibStubsPtr->xGetGeometry) /* 31 */
#endif
#ifndef XGetWindowProperty
#define XGetWindowProperty \
	(tkIntXlibStubsPtr->xGetWindowProperty) /* 32 */
#endif
#ifndef XGrabKeyboard
#define XGrabKeyboard \
	(tkIntXlibStubsPtr->xGrabKeyboard) /* 33 */
#endif
#ifndef XGrabPointer
#define XGrabPointer \
	(tkIntXlibStubsPtr->xGrabPointer) /* 34 */
#endif
#ifndef XKeysymToKeycode
#define XKeysymToKeycode \
	(tkIntXlibStubsPtr->xKeysymToKeycode) /* 35 */
#endif
#ifndef XMapWindow
#define XMapWindow \
	(tkIntXlibStubsPtr->xMapWindow) /* 36 */
#endif
#ifndef XMoveResizeWindow
#define XMoveResizeWindow \
	(tkIntXlibStubsPtr->xMoveResizeWindow) /* 37 */
#endif
#ifndef XMoveWindow
#define XMoveWindow \
	(tkIntXlibStubsPtr->xMoveWindow) /* 38 */
#endif
#ifndef XQueryPointer
#define XQueryPointer \
	(tkIntXlibStubsPtr->xQueryPointer) /* 39 */
#endif
#ifndef XRaiseWindow
#define XRaiseWindow \
	(tkIntXlibStubsPtr->xRaiseWindow) /* 40 */
#endif
#ifndef XRefreshKeyboardMapping
#define XRefreshKeyboardMapping \
	(tkIntXlibStubsPtr->xRefreshKeyboardMapping) /* 41 */
#endif
#ifndef XResizeWindow
#define XResizeWindow \
	(tkIntXlibStubsPtr->xResizeWindow) /* 42 */
#endif
#ifndef XSelectInput
#define XSelectInput \
	(tkIntXlibStubsPtr->xSelectInput) /* 43 */
#endif
#ifndef XSendEvent
#define XSendEvent \
	(tkIntXlibStubsPtr->xSendEvent) /* 44 */
#endif
#ifndef XSetIconName
#define XSetIconName \
	(tkIntXlibStubsPtr->xSetIconName) /* 45 */
#endif
#ifndef XSetInputFocus
#define XSetInputFocus \
	(tkIntXlibStubsPtr->xSetInputFocus) /* 46 */
#endif
#ifndef XSetSelectionOwner
#define XSetSelectionOwner \
	(tkIntXlibStubsPtr->xSetSelectionOwner) /* 47 */
#endif
#ifndef XSetWindowBackground
#define XSetWindowBackground \
	(tkIntXlibStubsPtr->xSetWindowBackground) /* 48 */
#endif
#ifndef XSetWindowBackgroundPixmap
#define XSetWindowBackgroundPixmap \
	(tkIntXlibStubsPtr->xSetWindowBackgroundPixmap) /* 49 */
#endif
#ifndef XSetWindowBorder
#define XSetWindowBorder \
	(tkIntXlibStubsPtr->xSetWindowBorder) /* 50 */
#endif
#ifndef XSetWindowBorderPixmap
#define XSetWindowBorderPixmap \
	(tkIntXlibStubsPtr->xSetWindowBorderPixmap) /* 51 */
#endif
#ifndef XSetWindowBorderWidth
#define XSetWindowBorderWidth \
	(tkIntXlibStubsPtr->xSetWindowBorderWidth) /* 52 */
#endif
#ifndef XSetWindowColormap
#define XSetWindowColormap \
	(tkIntXlibStubsPtr->xSetWindowColormap) /* 53 */
#endif
#ifndef XUngrabKeyboard
#define XUngrabKeyboard \
	(tkIntXlibStubsPtr->xUngrabKeyboard) /* 54 */
#endif
#ifndef XUngrabPointer
#define XUngrabPointer \
	(tkIntXlibStubsPtr->xUngrabPointer) /* 55 */
#endif
#ifndef XUnmapWindow
#define XUnmapWindow \
	(tkIntXlibStubsPtr->xUnmapWindow) /* 56 */
#endif
#ifndef TkPutImage
#define TkPutImage \
	(tkIntXlibStubsPtr->tkPutImage) /* 57 */
#endif
#ifndef XParseColor
#define XParseColor \
	(tkIntXlibStubsPtr->xParseColor) /* 58 */
#endif
#ifndef XCreateGC
#define XCreateGC \
	(tkIntXlibStubsPtr->xCreateGC) /* 59 */
#endif
#ifndef XFreeGC
#define XFreeGC \
	(tkIntXlibStubsPtr->xFreeGC) /* 60 */
#endif
#ifndef XInternAtom
#define XInternAtom \
	(tkIntXlibStubsPtr->xInternAtom) /* 61 */
#endif
#ifndef XSetBackground
#define XSetBackground \
	(tkIntXlibStubsPtr->xSetBackground) /* 62 */
#endif
#ifndef XSetForeground
#define XSetForeground \
	(tkIntXlibStubsPtr->xSetForeground) /* 63 */
#endif
#ifndef XSetClipMask
#define XSetClipMask \
	(tkIntXlibStubsPtr->xSetClipMask) /* 64 */
#endif
#ifndef XSetClipOrigin
#define XSetClipOrigin \
	(tkIntXlibStubsPtr->xSetClipOrigin) /* 65 */
#endif
#ifndef XSetTSOrigin
#define XSetTSOrigin \
	(tkIntXlibStubsPtr->xSetTSOrigin) /* 66 */
#endif
#ifndef XChangeGC
#define XChangeGC \
	(tkIntXlibStubsPtr->xChangeGC) /* 67 */
#endif
#ifndef XSetFont
#define XSetFont \
	(tkIntXlibStubsPtr->xSetFont) /* 68 */
#endif
#ifndef XSetArcMode
#define XSetArcMode \
	(tkIntXlibStubsPtr->xSetArcMode) /* 69 */
#endif
#ifndef XSetStipple
#define XSetStipple \
	(tkIntXlibStubsPtr->xSetStipple) /* 70 */
#endif
#ifndef XSetFillRule
#define XSetFillRule \
	(tkIntXlibStubsPtr->xSetFillRule) /* 71 */
#endif
#ifndef XSetFillStyle
#define XSetFillStyle \
	(tkIntXlibStubsPtr->xSetFillStyle) /* 72 */
#endif
#ifndef XSetFunction
#define XSetFunction \
	(tkIntXlibStubsPtr->xSetFunction) /* 73 */
#endif
#ifndef XSetLineAttributes
#define XSetLineAttributes \
	(tkIntXlibStubsPtr->xSetLineAttributes) /* 74 */
#endif
#ifndef _XInitImageFuncPtrs
#define _XInitImageFuncPtrs \
	(tkIntXlibStubsPtr->_XInitImageFuncPtrs) /* 75 */
#endif
#ifndef XCreateIC
#define XCreateIC \
	(tkIntXlibStubsPtr->xCreateIC) /* 76 */
#endif
#ifndef XGetVisualInfo
#define XGetVisualInfo \
	(tkIntXlibStubsPtr->xGetVisualInfo) /* 77 */
#endif
#ifndef XSetWMClientMachine
#define XSetWMClientMachine \
	(tkIntXlibStubsPtr->xSetWMClientMachine) /* 78 */
#endif
#ifndef XStringListToTextProperty
#define XStringListToTextProperty \
	(tkIntXlibStubsPtr->xStringListToTextProperty) /* 79 */
#endif
#ifndef XDrawSegments
#define XDrawSegments \
	(tkIntXlibStubsPtr->xDrawSegments) /* 80 */
#endif
#ifndef XForceScreenSaver
#define XForceScreenSaver \
	(tkIntXlibStubsPtr->xForceScreenSaver) /* 81 */
#endif
#ifndef XDrawLine
#define XDrawLine \
	(tkIntXlibStubsPtr->xDrawLine) /* 82 */
#endif
#ifndef XFillRectangle
#define XFillRectangle \
	(tkIntXlibStubsPtr->xFillRectangle) /* 83 */
#endif
#ifndef XClearWindow
#define XClearWindow \
	(tkIntXlibStubsPtr->xClearWindow) /* 84 */
#endif
#ifndef XDrawPoint
#define XDrawPoint \
	(tkIntXlibStubsPtr->xDrawPoint) /* 85 */
#endif
#ifndef XDrawPoints
#define XDrawPoints \
	(tkIntXlibStubsPtr->xDrawPoints) /* 86 */
#endif
#ifndef XWarpPointer
#define XWarpPointer \
	(tkIntXlibStubsPtr->xWarpPointer) /* 87 */
#endif
#ifndef XQueryColor
#define XQueryColor \
	(tkIntXlibStubsPtr->xQueryColor) /* 88 */
#endif
#ifndef XQueryColors
#define XQueryColors \
	(tkIntXlibStubsPtr->xQueryColors) /* 89 */
#endif
#ifndef XQueryTree
#define XQueryTree \
	(tkIntXlibStubsPtr->xQueryTree) /* 90 */
#endif
#ifndef XSync
#define XSync \
	(tkIntXlibStubsPtr->xSync) /* 91 */
#endif
#endif /* AQUA */

#endif /* defined(USE_TK_STUBS) && !defined(USE_TK_STUB_PROCS) */

/* !END!: Do not edit above this line. */

#undef TCL_STORAGE_CLASS
#define TCL_STORAGE_CLASS DLLIMPORT

#endif /* _TKINTXLIBDECLS */
/*
 * xbytes.h --
 *
 *	Declaration of table to reverse bit order of bytes.
 *
 * Copyright (c) 1995 Sun Microsystems, Inc.
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id$
 */

#ifndef _XBYTES
#define _XBYTES

/*
 * The bits in a byte can be reversed so the least significant becomes the
 * most significant by indexing xBitReverseTable with the byte to be reversed.
 */

static unsigned char xBitReverseTable[256] = {
    0x00, 0x80, 0x40, 0xc0, 0x20, 0xa0, 0x60, 0xe0,
    0x10, 0x90, 0x50, 0xd0, 0x30, 0xb0, 0x70, 0xf0,
    0x08, 0x88, 0x48, 0xc8, 0x28, 0xa8, 0x68, 0xe8,
    0x18, 0x98, 0x58, 0xd8, 0x38, 0xb8, 0x78, 0xf8,
    0x04, 0x84, 0x44, 0xc4, 0x24, 0xa4, 0x64, 0xe4,
    0x14, 0x94, 0x54, 0xd4, 0x34, 0xb4, 0x74, 0xf4,
    0x0c, 0x8c, 0x4c, 0xcc, 0x2c, 0xac, 0x6c, 0xec,
    0x1c, 0x9c, 0x5c, 0xdc, 0x3c, 0xbc, 0x7c, 0xfc,
    0x02, 0x82, 0x42, 0xc2, 0x22, 0xa2, 0x62, 0xe2,
    0x12, 0x92, 0x52, 0xd2, 0x32, 0xb2, 0x72, 0xf2,
    0x0a, 0x8a, 0x4a, 0xca, 0x2a, 0xaa, 0x6a, 0xea,
    0x1a, 0x9a, 0x5a, 0xda, 0x3a, 0xba, 0x7a, 0xfa,
    0x06, 0x86, 0x46, 0xc6, 0x26, 0xa6, 0x66, 0xe6,
    0x16, 0x96, 0x56, 0xd6, 0x36, 0xb6, 0x76, 0xf6,
    0x0e, 0x8e, 0x4e, 0xce, 0x2e, 0xae, 0x6e, 0xee,
    0x1e, 0x9e, 0x5e, 0xde, 0x3e, 0xbe, 0x7e, 0xfe,
    0x01, 0x81, 0x41, 0xc1, 0x21, 0xa1, 0x61, 0xe1,
    0x11, 0x91, 0x51, 0xd1, 0x31, 0xb1, 0x71, 0xf1,
    0x09, 0x89, 0x49, 0xc9, 0x29, 0xa9, 0x69, 0xe9,
    0x19, 0x99, 0x59, 0xd9, 0x39, 0xb9, 0x79, 0xf9,
    0x05, 0x85, 0x45, 0xc5, 0x25, 0xa5, 0x65, 0xe5,
    0x15, 0x95, 0x55, 0xd5, 0x35, 0xb5, 0x75, 0xf5,
    0x0d, 0x8d, 0x4d, 0xcd, 0x2d, 0xad, 0x6d, 0xed,
    0x1d, 0x9d, 0x5d, 0xdd, 0x3d, 0xbd, 0x7d, 0xfd,
    0x03, 0x83, 0x43, 0xc3, 0x23, 0xa3, 0x63, 0xe3,
    0x13, 0x93, 0x53, 0xd3, 0x33, 0xb3, 0x73, 0xf3,
    0x0b, 0x8b, 0x4b, 0xcb, 0x2b, 0xab, 0x6b, 0xeb,
    0x1b, 0x9b, 0x5b, 0xdb, 0x3b, 0xbb, 0x7b, 0xfb,
    0x07, 0x87, 0x47, 0xc7, 0x27, 0xa7, 0x67, 0xe7,
    0x17, 0x97, 0x57, 0xd7, 0x37, 0xb7, 0x77, 0xf7,
    0x0f, 0x8f, 0x4f, 0xcf, 0x2f, 0xaf, 0x6f, 0xef,
    0x1f, 0x9f, 0x5f, 0xdf, 0x3f, 0xbf, 0x7f, 0xff,
};

#endif /* _XBYTES */

/*
 * Local Variables:
 * mode: c
 * c-basic-offset: 4
 * fill-column: 78
 * End:
 */
