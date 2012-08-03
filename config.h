/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[]            = "Ubuntu:size=8:antialias=true:hinting=true";
//static const char font[]			  = "Droid Sans:Bold:size=8:antialias=true:hinting=true";
/* gaia212 */
static const char normbordercolor[] = "#90B4B0";
static const char normbgcolor[]     = "#6D9F99";
static const char normfgcolor[]     = "#F9F9F9";
static const char selbordercolor[]  = "#FDBE45";
static const char selbgcolor[]      = "#6D9F99";
static const char selfgcolor[]      = "#FFA905";
static const char urgbordercolor[]  = "#A62A3E";
static const char urgbgcolor[]      = "#000C1A";
static const char urgfgcolor[]      = "#A62A3E";
/* bohoomil */
//static const char normbordercolor[] = "#192033";
//static const char normbgcolor[]     = "#000C1A";
//static const char normfgcolor[]     = "#ACB4BF";
//static const char selbordercolor[]  = "#B27D12";
//static const char selbgcolor[]      = "#000C1A";
//static const char urgbordercolor[]  = "#A62A3E";
//static const char urgbgcolor[]      = "#000C1A";
//static const char urgfgcolor[]      = "#A62A3E";
static const unsigned int systrayspacing = 2;     // systray spacing
static const unsigned int borderpx       = 1;     // border pixel of windows
static const unsigned int gappx          = 2;     // gap pixel between windows
static const unsigned int snap           = 2;     // snap pixel
static const Bool showbar                = True;  // False means no bar
static const Bool showsystray            = True;  // False means no systray
static const Bool topbar                 = True;  // False means bottom bar

/* layout(s) */
static const float mfact      = 0.63;  // factor of master area size [0.05..0.95]
static const int nmaster      = 1;     // number of clients in master area
static const Bool resizehints = False; // True means respect size hints in tiled resizals

static const Layout layouts[] = {
/*    symbol   gaps   arrange function */
    { "T",   True,  tile    }, // first entry is default
    { "B",   True,  bstack  },
    { "C",   True,  chat    },
    { "M",   False, monocle },
    { "F",   False, NULL    }, // no layout function means floating behavior
};

/* tagging */
static const Tag tags[] = {
    /* name    layout       mfact  nmaster*/
    { "web",   &layouts[3], -1,    -1 },
    { "chill", &layouts[2], 0.80,  -1 },
    { "term",  &layouts[0], -1,    -1 },
    { "media", &layouts[3], -1,    -1 },
    { "work",  &layouts[3], -1,    -1 },
};

static const Rule rules[] = {
    /*WM_CLASS     WM_CLASS    WM_NAME
	  class        instance    title               tags mask     isfloating   monitor */
    { "Chromium",  NULL,       NULL,               1,            False,       -1 },
    { "Emesene",   NULL,       NULL,               1 << 1,       False,       -1 },
    { "Skype",     NULL,       NULL,               1 << 1,       False,       -1 },
    { "Skype",     NULL,       "Call with Aggi~",  1 << 1,       True,        -1 },
	{ NULL,        "ncmpcpp",  NULL,               1 << 3,       False,       -1 },
    { "MPlayer",   NULL,       NULL,               1 << 3,       True,        -1 },
    { "Gimp",      NULL,       NULL,               1 << 3,       False,       -1 },
    { "llpp",      NULL,       NULL,               1 << 4,       False,       -1 },
    { "Gnumeric",  NULL,       NULL,               1 << 4,       False,       -1 },
    { "Abiword",   NULL,       NULL,               1 << 4,       False        -1 },
};

/* key definitions */
#define MODKEY Mod1Mask
#define MONKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenu[]    = { "dmenu_run", "-p", "Uitvoeren:", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *kill[]     = { "xkill", NULL };
static const char *lock[]     = { "slock", NULL };
static const char *halt[]     = { "dmenu_shutdown", NULL };
static const char *term[]     = { "urxvtc", NULL };
static const char *browser[]  = { "chromium", NULL };
//static const char *files[]    = { "urxvtc", "-name", "ranger", "-e", "ranger", NULL };
static const char *files[]	  = { "thunar", };
static const char *music[]    = { "urxvtc", "-name", "ncmpcpp", "-e", "ncmpcpp", NULL };
static const char *msn[]      = { "emesene", "-s", NULL };
static const char *scrot[]    = { "scrot", NULL};
static const char *volup[]    = { "amixer", "-q", "sset", "Master", "5%+", "unmute", NULL };
static const char *voldown[]  = { "amixer", "-q", "sset", "Master", "5%-", "unmute", NULL };
static const char *volmute[]  = { "amixer", "-q", "sset", "Master", "toggle", NULL };
static const char *mpdplay[]  = { "mpc", "toggle", NULL };
static const char *mpdnext[]  = { "mpc", "next", NULL };
static const char *mpdprev[]  = { "mpc", "prev", NULL };
static const char *mpdstop[]  = { "mpc", "stop", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
    { MODKEY,                       XK_r,            spawn,          {.v = dmenu } },
    { MODKEY,                       XK_x,            spawn,          {.v = kill } },
    { MODKEY,                       XK_l,            spawn,          {.v = lock } },
    { MODKEY,                       XK_Escape,       spawn,          {.v = halt } },
    { MODKEY,                       XK_1,            spawn,          {.v = term } },
    { MODKEY,                       XK_2,            spawn,          {.v = browser } },
    { MODKEY,                       XK_3,            spawn,          {.v = files } },
    { MODKEY,                       XK_4,            spawn,          {.v = music } },
    { MODKEY,                       XK_5,            spawn,          {.v = msn } },
    { 0,                            XK_Print,        spawn,          {.v = scrot } },
    { 0,                            0x1008ff13,      spawn,          {.v = volup } },
    { 0,                            0x1008ff11,      spawn,          {.v = voldown } },
    { 0,                            0x1008ff12,      spawn,          {.v = volmute } },
    { 0,                            0x1008ff14,      spawn,          {.v = mpdplay } },
    { 0,                            0x1008ff17,      spawn,          {.v = mpdnext } },
    { 0,                            0x1008ff16,      spawn,          {.v = mpdprev } },
    { 0,                            0x1008ff15,      spawn,          {.v = mpdstop } },
    { MODKEY|ControlMask,           XK_b,            togglebar,      {0} },
    { MODKEY|ControlMask,           XK_q,            quit,           {0} },
    { MODKEY,                       XK_Right,        focusstack,     {.i = +1 } },
    { MODKEY,                       XK_Left,         focusstack,     {.i = -1 } },
    { MODKEY,                       XK_Return,       zoom,           {0} },
    { MODKEY,                       XK_Tab,          view,           {0} },
    { MODKEY,                       XK_q,            killclient,     {0} },
    { MODKEY,                       XK_bracketleft,  setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_bracketright, setmfact,       {.f = +0.05} },
    { MODKEY,                       XK_equal,        incnmaster,     {.i = +1 } },
    { MODKEY,                       XK_minus,        incnmaster,     {.i = -1 } },
    { MODKEY,                       XK_space,        setlayout,      {0} },
    { MODKEY|ShiftMask,             XK_f,            togglefloating, {0} },
    { MODKEY,                       XK_t,            setlayout,      {.v = &layouts[0] } },
    { MODKEY,                       XK_b,            setlayout,      {.v = &layouts[1] } },
    { MODKEY,                       XK_c,            setlayout,      {.v = &layouts[2] } },
    { MODKEY,                       XK_m,            setlayout,      {.v = &layouts[3] } },
    { MODKEY,                       XK_f,            setlayout,      {.v = &layouts[4] } },
    TAGKEYS(                        XK_F1,                           0)
    TAGKEYS(                        XK_F2,                           1)
    TAGKEYS(                        XK_F3,                           2)
    TAGKEYS(                        XK_F4,                           3)
    TAGKEYS(                        XK_F5,                           4)
    { MODKEY,                       XK_0,            view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,             XK_0,            tag,            {.ui = ~0 } },
    { MONKEY,                       XK_Left,         focusmon,       {.i = -1 } },
    { MONKEY,                       XK_Right,        focusmon,       {.i = +1 } },
    { MONKEY|ShiftMask,             XK_Left,         tagmon,         {.i = -1 } },
    { MONKEY|ShiftMask,             XK_Right,        tagmon,         {.i = +1 } },

};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = term } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

