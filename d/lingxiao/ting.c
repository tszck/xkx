// Room: /d/lingxiao/ting.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM; 
#include <ansi.h>
void create()
{
	set("short", "戲梅亭");
	set("long",@LONG 
這裏是凌霄城的戲梅亭，是凌霄城主白自在平時最喜歡來的地方。
從這裏俯瞰羣山，披襟當風，只覺萬裏江山，不如金樽一醉。在廳柱上
刻着一句詩(poem)，是白老爺子酒後性至，仗劍所留。但有人卻説白老
爺子生平最是好名，這樣説是自己打自己嘴巴，可也沒人正直到敢在白
老爺子面前譏諷半句。
LONG);
	set("exits", ([
		"west" : __DIR__"meiroad3",
	])); 
	set("objects", ([ 
		__DIR__"obj/ban" : 3,
	])); 
	set("item_desc", ([
		"poem" : "忍把浮名，換了淺酌低唱。\n",
	]) );
	set("outdoors", "lingxiao");
	set("coor/x", -30980);
	set("coor/y", -8890);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

