// /kaifeng/yaqi.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "雅琪軒");
	set("long", @LONG
雅琪軒是間出售官瓷的商店，其間也出售些書畫精品。你瞧了一下，
店鋪中四面木架子上大小各類的瓷器，大多是富貴人家用的。象粗瓷，
粗碗之類東西，只能從地攤買了。
LONG
	);
	set("objects", ([
		__DIR__"npc/liuzhanggui" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"road3",
	]));

	setup();
	replace_program(ROOM);
}
