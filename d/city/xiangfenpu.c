// Room: /yangzhou/xiangfenpu.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","戴記香粉鋪");
	set("long",@LONG
「天下香料，莫如揚州」，這裏便是揚州香粉鋪子中最好的一家「
戴春林」香粉鋪。一進入鋪子，一種混雜的香氣撲鼻而來。鋪子邊上擺
着幾面鏡子，中間是一紅木櫃臺。幾個年輕女子正在試用粉餅胭脂，另
有幾個老媽子正在和夥計商量着什麼。隨着你進來，一個夥計緩緩的站
起身來。
LONG );
	set("exits", ([
		"north" : __DIR__"dashidongjie",
	]));
	set("objects", ([
		__DIR__"npc/daichunlin" : 1,
	]));
	set("coor/x", 60);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}