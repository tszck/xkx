//  Room:  /d/luoyang/xiaojiudian.c

inherit  ROOM;

void  create  ()
{
	set("short",  "酒肆");
	set("long",  @LONG
這裏是個小酒肆，七八名無賴正在店中賭骰子。店裏賣些混酒和豬
鴨下水，你看了一點胃口都沒有。無賴們看着你，一副要痛扁你一頓，
或者賭骰子狠出你一把老千的樣子，看來還是走吧。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south" :  __DIR__"xiaojie1",
	]));
	set("objects",  ([
		__DIR__"npc/wulai" : 3,
	]));
	set("coor/x", -400);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
