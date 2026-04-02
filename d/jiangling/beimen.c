//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "北門");
	set("long", @LONG
這是荊州北城門。城牆雖然是土製的，卻也雄偉壯觀。從這裏往南
走，就是熱鬧的荊州西街了。北方是一條黃土路。
LONG );
	set("exits", ([
		"south" : __DIR__"xijie1",
		"north" : __DIR__"tulu",
	]));
	set("objects", ([
		"/d/huashan/npc/haoke" : 1,
		"/d/taishan/npc/dao-ke" : 2,
	]));
	set("outdoors", "jiangling");
	set("coor/x", -1500);
	set("coor/y", -1100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}