//  Room:  /d/luoyang/lvzhulin.c

inherit  ROOM;

void  create  ()
{
	set("short",  "綠竹林");
	set("long",  @LONG
一片綠茸般的竹林把燥熱擋在視野之外，這裏是一片清涼世界。小
石子路在竹林中穿梭而過，石子間是細密的青苔，透着一股涼爽，自腳
跟沁入胸臆。北面是個小院子。琴聲益發悅耳了。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south"  :  __DIR__"xiaoxiang",
		"north"  :  __DIR__"lvzhuxiaoyuan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "luoyang");
	set("coor/x", -380);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}