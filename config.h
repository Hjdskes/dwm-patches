/* See LICENSE file for copyright and license details. */
#include <X11/XF86keysym.h>

/* appearance */
static const char font[]            = "Ubuntu Mono:size=9:antialias=true:hinting=true"; /*:rgba=rgb:hintstyle=hintsfull:lcdfilter=lcdlight:dpi=96";*/
/*static const char font[]            = "Source Sans Pro:Semibold:size=9:antialias=true:hinting=true:rgba=rgb:hintstyle=hintsfull:lcdfilter=lcdlight:dpi=96";*/
#define NUMCOLORS 4
static const char colors[NUMCOLORS][ColLast][9] = {
    /* border   foreground  background */
    { "#BDBDBD", "#8C8C8C", "#0A1724" },
    { "#4A90D9", "#4A90D9", "#0A1724" },
    { "#DC322F", "#DC322F", "#0A1724" },
    { "#16596A", "#16596A", "#0A1724" },
};

static const unsigned int borderpx       = 1;      /* Border pixel of windows */
static const unsigned int snap           = 2;      /* Snap pixel */
static const unsigned int minwsz         = 20;     /* Minimal heigt of a client for smfact */
static const char chatclient[]           = "jente_etnej - Skype™"; /* Name of chat client for chatlayout */
static const char clock_fmt[]            = "%a %d %b, %R";   /* Clock format on the bar */
static const char statusprogram[]        = "dwmst"; /* program to execute to set DWM's status */
static const Bool showbar                = True;   /* False means no bar */
static const Bool topbar                 = True;   /* False means bottom bar */

/* layouts */
static const float mfact      = 0.63;  /* factor of master area size [0.05..0.95] */
static const float smfact     = 0.00;  /* factor of tiled clients [0.05..1.00] */
static const int nmaster      = 1;     /* number of clients in master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
  /* symbol arrange */
	{ " T",  tile },
	{ " C",  chat },
	{ " B",  bstack },
	{ " M",  monocle },
	{ " F",  NULL },
};

/* tagging */
static const Tag tags[] = {
	/* name		 layout       mfact	nmaster */
	{ "1:web",	 &layouts[0], -1,	-1 },
	{ "2:chill", &layouts[1], 0.80,	-1 },
	{ "3:term",	 &layouts[0], -1,	-1 },
	{ "4:media", &layouts[3], -1,	-1 },
	{ "5:work",	 &layouts[3], -1,	-1 },
};

static const Rule rules[] = {
    /*WM_CLASS              WM_CLASS    WM_NAME
      class                 instance    title               tags mask   isfloating  monitor */
    { "Firefox",            NULL,       NULL,               1,          False,      -1 },
    { "Skype",              NULL,       NULL,               1 << 1,     False,      -1 },
    { "Skype",              NULL,       "Call with Aggi~",  1 << 1,     True,       -1 },
	{ "st", 			    NULL,       NULL,               1 << 2,     False,      -1 },
    { "Gedit",              NULL,       NULL,               1 << 2,     False,      -1 },
    { "Audacious",          NULL,       NULL,               1 << 3,     False,      -1 },
    { "MPlayer",            NULL,       NULL,               1 << 3,     True,       -1 },
    { "Gimp",               NULL,       NULL,               1 << 3,     False,      -1 },
    { "Transmission-gtk",   NULL,       NULL,               1 << 3,     False,      -1 },
    { "VirtualBox",         NULL,       NULL,               1 << 3,     False,      -1 },
    { "Evince",             NULL,       NULL,               1 << 4,     False,      -1 },
};

/* key definitions */
#define MODKEY Mod1Mask
#define MONKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenu[]   = { "dmenu_run", "-f", "-p", "Uitvoeren:", "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG], "-sb", colors[1][ColBG], "-sf", colors[1][ColFG], NULL };
static const char *find[]    = { "dmenu_finder", NULL };
static const char *dmfm[]    = { "dmenu_fm", NULL };
static const char *term[]    = { "st", NULL };
static const char *browser[] = { "firefox", NULL };
static const char *files[]   = { "nautilus", NULL };
static const char *music[]   = { "audacious", NULL };
static const char *skype[]   = { "skype", NULL };
static const char *scrot[]   = { "gnome-screenshot", NULL };
static const char *kill[]    = { "xkill", NULL };
static const char *lock[]    = { "slock", NULL };
static const char *halt[]    = { "dmenu_shutdown", NULL };
static const char *volup[]   = { "amixer", "-q", "sset", "Master", "5%+", "unmute", NULL };
static const char *voldown[] = { "amixer", "-q", "sset", "Master", "5%-", "unmute", NULL };
static const char *volmute[] = { "amixer", "-q", "sset", "Master", "toggle", NULL };
static const char *play[]    = { "audtool", "playback-playpause", NULL };
static const char *next[]    = { "audtool", "playlist-advance", NULL };
static const char *prev[]    = { "audtool", "playlist-reverse", NULL };
static const char *stop[]    = { "audtool", "playback-stop", NULL };


static Key keys[] = {
	/* modifier                 key        function        argument */
	{ MODKEY,                   XK_r,                       spawn,          {.v = dmenu } },
	{ MODKEY,                   XK_x,                       spawn,          {.v = kill } },
	{ MODKEY,                   XK_l,                       spawn,          {.v = lock } },
	{ MODKEY,                   XK_Escape,                  spawn,          {.v = halt } },
	{ MODKEY,                   XK_z,                       spawn,          {.v = find } },
	{ MODKEY,                   XK_o,                       spawn,          {.v = dmfm } },
	{ MODKEY,                   XK_1,                       spawn,          {.v = term } },
	{ MODKEY,                   XK_2,                       spawn,          {.v = browser } },
	{ MODKEY,                   XK_3,                       spawn,          {.v = files } },
	{ MODKEY,                   XK_4,                       spawn,          {.v = music } },
	{ MODKEY,                   XK_5,                       spawn,          {.v = skype } },
	{ 0,                        XK_Print,                   spawn,          {.v = scrot } },
	{ 0,                        XF86XK_AudioRaiseVolume,    spawn,          {.v = volup } },
	{ 0,                        XF86XK_AudioLowerVolume,    spawn,          {.v = voldown } },
	{ 0,                        XF86XK_AudioMute,           spawn,          {.v = volmute } },
	{ 0,                        XF86XK_AudioPlay,           spawn,          {.v = play } },
	{ 0,                        XF86XK_AudioNext,           spawn,          {.v = next } },
	{ 0,                        XF86XK_AudioPrev,           spawn,          {.v = prev } },
	{ 0,                        XF86XK_AudioStop,           spawn,          {.v = stop } },
	{ MODKEY|ControlMask,       XK_b,                       togglebar,      {0} },
	{ MODKEY|ControlMask,       XK_q,                       quit,           {0} },
	{ MODKEY,                   XK_Tab,                     focusstack,     {.i = +1 } },
	{ MODKEY|ShiftMask,         XK_Tab,                     focusstack,     {.i = -1 } },
	{ MODKEY,                   XK_Return,                  zoom,           {0} },
	{ MODKEY|ControlMask,       XK_Tab,                     view,           {0} },
	{ MODKEY,                   XK_q,                       killclient,     {0} },
	{ MODKEY,                   XK_bracketleft,             setmfact,       {.f = -0.05} },
	{ MODKEY,                   XK_bracketright,            setmfact,       {.f = +0.05} },
	{ MODKEY,                   XK_0,                       setsmfact,      {.f = +0.05} },
	{ MODKEY,                   XK_p,                       setsmfact,      {.f = -0.05} },
	{ MODKEY,                   XK_equal,                   incnmaster,     {.i = +1 } },
	{ MODKEY,                   XK_minus,                   incnmaster,     {.i = -1 } },
	{ MODKEY,                   XK_space,                   setlayout,      {0} },
	{ MODKEY,                   XK_Up,                      pushup,         {0} },
	{ MODKEY,                   XK_Down,                    pushdown,       {0} },
	{ MODKEY,                   XK_Left,                    cycle,          {.i = -1 } },
	{ MODKEY,                   XK_Right,                   cycle,          {.i = +1 } },
	{ MODKEY|ShiftMask,         XK_Left,                    tagcycle,       {.i = -1 } },
	{ MODKEY|ShiftMask,         XK_Right,                   tagcycle,       {.i = +1 } },
	{ MODKEY|ShiftMask,         XK_f,                       togglefloating, {0} },
	{ MODKEY,                   XK_t,                       setlayout,      {.v = &layouts[0] } },
	{ MODKEY,                   XK_c,                       setlayout,      {.v = &layouts[1] } },
	{ MODKEY,                   XK_b,                       setlayout,      {.v = &layouts[2] } },
	{ MODKEY,                   XK_m,                       setlayout,      {.v = &layouts[3] } },
	{ MODKEY,                   XK_f,                       setlayout,      {.v = &layouts[4] } },
	TAGKEYS(                    XK_F1,                      0)
	TAGKEYS(                    XK_F2,                      1)
	TAGKEYS(                    XK_F3,                      2)
	TAGKEYS(                    XK_F4,                      3)
	TAGKEYS(                    XK_F5,                      4)
	{ MODKEY,                   XK_a,                       view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,         XK_a,                       tag,            {.ui = ~0 } },
	{ MONKEY,                   XK_Left,                    focusmon,       {.i = -1 } },
	{ MONKEY,                   XK_Right,                   focusmon,       {.i = +1 } },
	{ MONKEY|ShiftMask,         XK_Left,                    tagmon,         {.i = -1 } },
	{ MONKEY|ShiftMask,         XK_Right,                   tagmon,         {.i = +1 } },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkClock,             0,              Button1,        spawn,          {.v = term } },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = term } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        tag,            {0} },
};

