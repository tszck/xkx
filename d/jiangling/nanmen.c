//Edited by fandog, 02/18/2000
inherit ROOM;
void create()
{
	set("short", "南門");
	set("long", @LONG
這是荊州南城門。城牆上，赫然可見三行用石灰泥書寫的數目字。
每個字都是尺許見方，遠遠便能望見，“四、五十一、三十三、二十八
……”奇怪的是，這幾行字離地二丈有餘。北邊就是荊州城了，南邊是
一條山道，蜿蜒伸展通向城南一片亂石岡。
LONG );
	set("outdoors", "jiangling");
	set("exits", ([
		"south" : __DIR__"shandao1",
		"north" : __DIR__"xijie4",
	]));
	set("objects", ([
		__DIR__"npc/jiaoshu"   : 1,
		"/d/huashan/npc/haoke"  : 2,
		"/d/taishan/npc/jian-ke": 2,
	]));
	set("coor/x", -1500);
	set("coor/y", -2050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}