// Room: /d/chengdu/fengyuting.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "風雨亭");
	set("long", @LONG
你站在亭裏，看着亭外灰濛濛的天，不禁有一種“山雨欲來風滿樓”
的感覺。向西望是層起彼伏的街道，行人來來往往。向東望是山麓，鬱
鬱蔥蔥的樹林中露出了一角飛掾。遠處傳來了肅穆莊重的鐘聲，你的靈
臺一片清明。
LONG	);

	set("exits", ([
		"south" : __DIR__"gongqiao1",
	]));
	set("objects", ([
	    __DIR__"npc/youke" : 2,
	]));
	set("coor/x", -8020);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

