// Room: /d/tiezhang/chufang.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "廚房");
	set("long", @LONG
這裏是鐵掌幫的廚房。正面擺着一個大爐竈，幾乎佔去了一半的房
間。竈上留有很多火眼，可同時做很多種菜。幾位幫中高薪聘來的廚子
正在來回忙碌着。整間屋內瀰漫着各種飯菜的香味，聞了讓人垂涎欲滴。
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"zoulang3",
	]));
	set("objects", ([ 
		__DIR__"obj/hsnr" : 1,
		__DIR__"obj/ruzhu" : 1,
		__DIR__"obj/fan" : 1,
	]));
	set("no_clean_up", 0);

	set("coor/x", -2060);
	set("coor/y", -1950);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}