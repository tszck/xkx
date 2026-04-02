// Room: /d/henshan/dadian.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "大殿");
        set("long", @LONG
這裏是南嶽大殿，供祭祀炎帝之用。大殿結構為重檐歇山頂，頂覆
七彩琉璃。殿高七十二尺，正面七間，有石柱七十二根，合南嶽七十二
峯之數。殿中南嶽聖帝寶相莊嚴。南嶽廟之雄為衡山小四絕之一。 
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "south"  : __DIR__"yushulou",
           "north"  : __DIR__"houdian",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -300);
	set("coor/y", -1130);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
