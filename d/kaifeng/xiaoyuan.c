// /kaifeng/xiaoyuan.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "小院");
	set("long", @LONG
你一腳踏進來，不由得喊了聲好，只見修篁一片，間中是兩棵佛祖
曾在其下悟道的菩提樹。小路沿着修竹而彎，北面路的盡頭就是方丈大
師傅的住所，也是他平常接待貴客的地方。
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"fangzhang",
		"west" : __DIR__"cangjing1",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
