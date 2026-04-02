//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "客堂");
	set ("long", @LONG
這裏是萬家請貴重客人的小客堂。中間一個小圓紅木桌上，擺滿了
一桌酒席，等着客人上坐。鏤雕窗外，可以看到花園的春色。
LONG);
	set("exits", ([
		"up"     : __DIR__"donglou",
		"west"   : __DIR__"zoulang1",
		"east"  : __DIR__"huayuan",
	]));
	set("objects", ([
		__DIR__"obj/babao" : 1,
		__DIR__"obj/longfeng" : 1,
	]));
  
	set("coor/x", -1487);
	set("coor/y", -2040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
