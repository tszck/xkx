//ROOM: shanjiao.c

inherit ROOM;

void create()
{
	set("short", "縹緲峯山腳");
	set("long",@LONG
這裏是縹緲峯山腳，抬頭上望，縹緲峯聳入雲天，峯頂白雲繚繞，
宛若仙境。白雲深處隱約可見瓊樓玉宇，那就是令江湖人物聞名喪膽的
『靈鷲宮』。聽說宮中住着一些武藝高強的女俠，而且只收女弟子爲徒。
LONG );
	set("outdoors", "lingjiu");
	set("exits", ([
		"westup" : __DIR__"ya",
		"southdown" : "/d/xingxiu/tianroad2"
	]));
	set("objects",([
		__DIR__"npc/jiuyi" : 1,
	]));
	set("coor/x", -50000);
	set("coor/y", 30000);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}