inherit ROOM;

void create()
{
	set("short", "道具房");
	set("long", @LONG
這是一間道具房。擺着一些桃花弟子們常用的東西。房裏好象黑
乎乎的，靠窗處有一張斑駁長桌和一把靠背椅，雖是白天還點着小油
燈。啞僕看到你進來，就使勁瞪着你，雖然口不能言，可你還是心中
惴惴。
LONG );
	set("exits", ([
		"south" : __DIR__"zoulang3",
	]));
	set("objects", ([
		__DIR__"obj/xiang" : 1,
	]) );
	set("coor/x", 8990);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}