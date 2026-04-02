//  Room:  /d/luoyang/xiaoxiang.c

inherit  ROOM;

void  create  ()
{
	set("short",  "中通巷");
	set("long",  @LONG
你剛踏進巷子，便聽得琴韻丁冬，有人正在撫琴，小巷中一片清涼
寧靜，和外面的洛陽城宛然是兩個世界。窄窄的巷子盡頭，好大一片綠
竹叢，迎風搖曳，雅緻天然。你不禁感嘆道：“這裏的居士好會享清福
啊！”
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"      :  __DIR__"tongtuo",
		"north"     :  __DIR__"lvzhulin",
		"southwest" :  __DIR__"xiaojie2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "luoyang");
	set("coor/x", -380);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
