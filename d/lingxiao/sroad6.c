// Room: /d/lingxiao/sroad6.c
// Last Modified by Winder on Jul. 15 2001

#include <room.h>
inherit ROOM;
void create()
{
	set("short","山路");
	set("long",@LONG 
走到這裏，反覺暖和一些了，風仍在刮，但耳邊只聽到叮噹的流水
聲。一道白波從巖縫中垂下，簌簌清流令人心神一爽，左邊熱氣騰騰，
煙霧瀰漫，顯然是個溫泉，右邊零零落落有幾間木屋，是凌霄弟子巡山
看守時住宿之地。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"west"    : __DIR__"water", 
		"east"    : __DIR__"muwu",
		"south"   : __DIR__"sroad5",
		"northup" : __DIR__"fentianya", 
	]));
	create_door("east", "木門", "west", DOOR_CLOSED);
	set("no_clean_up", 0);
	set("coor/x", -31000);
	set("coor/y", -8950);
	set("coor/z", 110);
	setup();
	replace_program(ROOM); 
}

