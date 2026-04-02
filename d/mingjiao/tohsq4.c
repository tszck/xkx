//TOHSQ4.C

inherit ROOM;

void create()
{
	set("short", "山林路");
	set("long", @LONG
山路到這裏似乎變得寬闊了些。清新的山風撲面而來，令人精神頓
為一爽。遠處傳來淙淙水聲，漸行漸遠。山壁上掛滿了厚密的藤蘿，隨
風輕輕搖弋。
LONG );
	set("exits", ([
		"north" : __DIR__"tohsq5",
		"south" : __DIR__"tohsq2",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -52020);
	set("coor/y", 890);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}