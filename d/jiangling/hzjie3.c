//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "漢正街");
	set ("long", @LONG
這是武漢最繁華的街道。從大江南北來的各色人等，熙熙攘攘，摩
肩接踵。西邊一個大棚子裏擺放了許多菊花，奼紫嫣紅，令人歎爲觀止。
東邊是有名的琴臺。
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
		"east" : __DIR__"qintai",
		"west" : __DIR__"juhuahui",
		"south": __DIR__"hzjie4",
		"north": __DIR__"hzjie2",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1500);
	set("coor/y", -2120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
