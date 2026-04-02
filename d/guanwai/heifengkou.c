// /guanwai/xiaotianchi.c

inherit ROOM;

void create()
{
	set("short", "黑風口");
	set("long", @LONG
這裏是密林中的險惡之境周圍是為茂密的松林，不見天光。林中傳
來野獸飢餓之極的嘶吼。四處有不知名的草菰和野果，可你一點也不敢
嚐嚐。林木幽暗深邃，似乎暗藏殺機。你到了此處，心膽俱裂，只想快
點離開。
LONG );
	set("outdoors", "changbai");
	set("exits", ([
		"east"     : __DIR__"xiaotianchi",
		"westdown" : __DIR__"milin3",
	]));
	set("objects", ([
		__DIR__"npc/bear" : 1,
	]));
	set("coor/x", 6170);
	set("coor/y", 5200);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}