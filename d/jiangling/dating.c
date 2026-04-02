//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "大廳");
	set ("long", @LONG
這是萬家爲慶祝老爺子五十大壽佈置的大廳，前來拜壽的客人已陸
續就座，幾個丫鬟僕人正忙着端茶送水，大廳上一個身形魁梧的老者正
在和衆賓客周旋。
LONG);
	set("exits", ([
		"west"  : __DIR__"damen",
		"east"  : __DIR__"zoulang1",
		"south" : __DIR__"nanlou",
		"north" : __DIR__"beilou",
	]));
	set("objects", ([
		__DIR__"npc/wanzhenshan" : 1,
		__DIR__"npc/lvtong"      : 1,
		__DIR__"npc/lukun"       : 1,
		__DIR__"npc/zhouqi"      : 1,
	]));

	set("coor/x", -1489);
	set("coor/y", -2040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
