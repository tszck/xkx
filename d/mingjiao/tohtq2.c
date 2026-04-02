//TOHTQ2.C

inherit ROOM;

void create()
{
	set("short", "山谷路");
	set("long", @LONG
這裏是一條很普通的山路，路邊的樹林密集，芳草流香，草叢中星
星點點地點綴着一些白色野花，漸行漸低，兩邊草木茂盛，處高崖下，
天色漸陰。
LONG );
	set("exits", ([
		"southwest" :__DIR__"tohtq1",
		"northdown" :__DIR__"tohtq3",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -52040);
	set("coor/y", 880);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}