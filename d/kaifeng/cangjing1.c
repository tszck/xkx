// /kaifeng/cangjing1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "藏經樓");
	set("long", @LONG
藏經樓是一棟兩層小樓，閣樓中都是佛家經典，名貴稀少的都用檀
木盒盛放了。收藏在樓上，派有專人職司。你滿眼看去，到處是高低的
書架，
LONG);
	set("objects", ([
		__DIR__"npc/zhifa" : 1,
	]));
	set("exits", ([
		"up"   : __DIR__"cangjing2",
		"west" : __DIR__"houyuan",
		"east" : __DIR__"xiaoyuan",
	]));

	setup();
	replace_program(ROOM);
}
