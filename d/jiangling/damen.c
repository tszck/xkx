//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "大門");
	set ("long", @LONG
這是荊州大名鼎鼎的武林人物萬震山的住處。正值萬老英雄五十大
壽，硃紅大門外掛燈結綵，前來拜壽的客人談笑着走進大廳，鼓樂手吹
着迎賓的樂曲。
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
		"east"  : __DIR__"dating",
		"west"  : __DIR__"xijie4",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1490);
	set("coor/y", -2040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
