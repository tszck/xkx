// Room: /d/5lt/tzoffice.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "臺長辦公室");
	set  ("long",  @LONG
這裏就是臺長辦公室，屋內佈置雖然極爲簡單，但是一進門你的視
線就被牢牢吸引住了。
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"west"  :  __DIR__"mishuchu",
	]));
        set("objects", ([
		__DIR__"npc/yoyo": 1,
	]));
	set("no_fight", 1);
	set("coor/x", -175);
	set("coor/y", 30);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
