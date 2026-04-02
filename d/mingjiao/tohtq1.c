//TOHTQ1.C

inherit ROOM;

void create()
{
	set("short", "山谷路");
	set("long", @LONG
這裏是一條很普通的山路，路邊的樹林密集，芳草流香，草叢中星
星點點地點綴着一些白色野花，路面也越來越乾燥，遠處可見陣陣塵土
飛揚，爲這山谷陡增了幾分生氣。
LONG );
	set("exits", ([
		"southwest" :__DIR__"tojmq3",
		"northeast" :__DIR__"tohtq2",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -52050);
	set("coor/y", 870);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}