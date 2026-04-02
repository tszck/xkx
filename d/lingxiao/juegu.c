// Room: /d/lingxiao/jiugu.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","絕谷");
	set("long",@LONG
還好，你運氣好，從萬丈深淵上摔下來，居然摔到厚厚的雪堆上，
不但沒斷腿少胳膊，連皮都沒傷到一點。但是，到了這絕谷之下，如何
上去呢？攀攀(pan)看呢？
LONG);
	set("outdoors", "lingxiao");
	set("exits", ([
	]));
	set("coor/x", -31000);
	set("coor/y", -8980);
	set("coor/z", 60);
	set("no_clean_up", 0);
	setup();
} 
void init()
{
	add_action("do_pan","pan");
}
int do_pan()
{
	object me = this_player();
	message("vision", me->name() + "手腳並用，貓着腰往上爬。\n", environment(me), ({me}) );
	me->move(__DIR__"shiya");
	message("vision", me->name() + "從石崖下貓着腰爬了上來。\n", environment(me), ({me}) );
	return 1;
}

