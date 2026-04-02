//TOHSQ5.C

inherit ROOM;

void create()
{
	set("short", "山林路");
	set("long", @LONG
水聲越來越大，山間充滿了濃濃的水氣。山路上，斷裂的山隙中，
都流出一道道細細的泉水，匯成一股澄碧的小溪，向山下蜿蜒流去。周
圍綠意盪漾，鳥語鸚聲，如置身仙境。
LONG );
	set("exits", ([
		"north" : __DIR__"tohsq6",
		"south" : __DIR__"tohsq4",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -52020);
	set("coor/y", 900);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}