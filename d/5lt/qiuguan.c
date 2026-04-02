// Room: /d/5lt/qiuguan.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "羽毛球館");
	set  ("long",  @LONG
這裏是羽毛球館，開門不到半柱香的功夫，館內已經沒有空着的場
地了，場邊站滿了拿着球拍觀戰的人。
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"east"  :  __DIR__"nroad3",
	]));
	set("no_fight", 1);
	set("coor/x", -160);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
