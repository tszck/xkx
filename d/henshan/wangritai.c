// Room: /d/henshan/wangritai.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "望日臺");
        set("long", @LONG
望日臺緊鄰祝融殿。雞鳴夜起，登臺東望，遙見海門，雲水皆赤，
倏忽異彩，日輪盪漾，若沉若浮，稍之奮湧而起，光耀奪目。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southdown"  : __DIR__"shiziyan",
           "northup"    : __DIR__"zhurongdian",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -310);
	set("coor/y", -1000);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}
