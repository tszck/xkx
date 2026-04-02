// xuanya.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;
void create()
{
	set("short","懸崖");
	set("long",@LONG
這是華山上懸崖上的一片平臺，地勢險惡。平臺旁便是萬丈深淵，
低頭望下，只見一天雲海。華山弟子多在此練劍打坐，借天時地勢，勤
練武功。平時華山掌門也在此指點及考教門下弟子。
LONG);
	set("exits",([
		"west" : __DIR__"houyuan",
	]));
	set("outdoors", "huashan");
	set("no_clean_up", 0);
	set("coor/x", -870);
	set("coor/y", 210);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
 
