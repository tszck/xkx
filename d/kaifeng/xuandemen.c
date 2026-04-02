// /kaifeng/xuandemen.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "宣德門");
	set("long", @LONG
宣德門是開封的北城門，由於這裏歷來是皇城所在。城牆建築得格
外牢固。兩邊的藏兵洞主可容千人，其作用是當敵人攻破城門之時，由
伏兵殺出，截殺敵人。
LONG);
	set("objects", ([
		__DIR__"npc/guanbing" : 2,
	]));
	set("outdoors", "kaifeng");
	set("exits", ([
		"south" : __DIR__"road6",
		"north" : __DIR__"jiaowai",
	]));

	setup();
	replace_program(ROOM);
}
