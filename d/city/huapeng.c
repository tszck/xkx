// Room: /city/huapeng.c

inherit ROOM;

void create()
{
	set("short", "花棚");
	set("long", @LONG
這是在芍藥圃正中用不去皮的松樹搭成的一座花棚，樹上的樹葉依
舊，棚內椅座乃是用天然樹石，四周種滿花木青草，再以段段竹節引水，
流轉棚周，淙淙有聲。在此飲酒賞花真是意境無窮。
LONG );
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("exits", ([
		"west"       : __DIR__"chanzhimenqian",
	]));
	set("coor/x", -19);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}