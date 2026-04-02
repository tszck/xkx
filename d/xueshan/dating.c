// dating.c 大廳

inherit ROOM;

void create()
{
	set("short","大廳");
	set("long",@LONG
這裏是寺內的大廳，幾位有道的高僧在高聲辯論。看來正在引經據
典，爭鬥機鋒。
LONG );
	set("exits",([
		"east" : __DIR__"zoulang1",
		"west" : __DIR__"zoulang2",
		"northeast" : __DIR__"chanshi",
		"southeast" : __DIR__"cangjing",
		"northwest" : __DIR__"cangjingge",
	]));
	set("objects", ([
		CLASS_D("xueshan")+"/fawang" :1,
	]));
	set("coor/x", -70000);
	set("coor/y", -19890);
	set("coor/z", 130);
	setup();
}