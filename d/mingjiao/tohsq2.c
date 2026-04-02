//TOHSQ2.C

inherit ROOM;

void create()
{
	set("short", "山林路");
	set("long", @LONG
這裏地勢很陡峭，向北是一條連綿數十里的山谷，向南走，則是去
明教銳金旗方向的路。路兩旁蜂舞蝶影，山花爛漫，好一派野地風光。
但就在那叢林深處，迭翠之中，又讓人不覺感受到一陣蕭瑟的寒意。
LONG );
	set("exits", ([
		"southeast" : __DIR__"tohsq1",
		"northwest" : __DIR__"tohsq3",
		"north"     : __DIR__"tohsq4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -52020);
	set("coor/y", 880);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}