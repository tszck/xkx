//TOHSQ1.C

inherit ROOM;

void create()
{
	set("short", "山林路");
	set("long", @LONG
這裏是一條很普通的山路，路邊的樹林密集，芳草流香，草叢中星
星點點地點綴着一些白色野花，一股清泉叮叮咚咚地向山下流淌，遠處
傳來陣陣水聲，爲這山谷陡增了幾分氣勢。
LONG );
	set("exits", ([
		"southeast" : __DIR__"torjq3",
		"northwest" : __DIR__"tohsq2",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -52010);
	set("coor/y", 870);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}