// Room: path2.c
// Date: Feb.14 1998 by Java

inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "溪岸小路");
	set("long", @LONG
溪源轉北，陣陣水響帶着你來到草堂前。站在草堂照壁前，回首
浣花溪，想象萬紅漂墜，少女清歌浣花時節，別是一般滋味。西北邊
就是“萬裏橋西宅，百花潭北莊”的杜甫草堂了。
LONG );
	set("outdoors", "chengdu");
	set("exits", ([
		"northwest"  : __DIR__"path3",
		"northeast"  : __DIR__"huanhuaxi1",
		"southwest"  : __DIR__"path1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8060);
	set("coor/y", -2970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
