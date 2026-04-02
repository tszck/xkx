// /d/beijing/alley2.c
// Last Modified by winder on Jan. 18 2002

inherit ROOM;

void create()
{
	set("short", "楊柳衚衕");
	set("long", @LONG
街道上一個人也看不到。你突然有點害怕起來。東南邊有一家棺材
店。西南邊是一條黑漆漆的小巷，你不知道要不要繼續向裏走。“還是
往北迴去吧，免得。。。。。。”，心底裏一個聲音不住地對你說。
LONG );
	set("outdoors", "beijing");

	set("exits", ([
		"north"     : __DIR__"alley1",
		"southeast" : __DIR__"guancai1",
		"southwest" : __DIR__"alley3",
	]));
	set("no_clean_up", 0);

	set("coor/x", -220);
	set("coor/y", 4020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
