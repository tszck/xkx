// wdroad1.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一條青石大道上，人來人往非常繁忙，不時地有人騎着馬匆
匆而過。大道兩旁有一些小貨攤，似乎是一處集市。北邊通向揚州城。
東南是一大片樹林。
LONG );
	set("outdoors", "sanbuguan");
	set("exits", ([
		"south"     : __DIR__"wdroad2",
		"north"     : "/d/city/dujiangqiao",
	]));
        set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", -120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
