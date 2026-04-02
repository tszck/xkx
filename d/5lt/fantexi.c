//  Room:  /d/5lt/fantexi.c

inherit  ROOM;

void  create  ()
{
	set("short",  "飯特溪");
	set("long",  @LONG
這裏就是傳說中的飯特溪了。好一條清亮的小溪！你把手伸進湍湍
流淌的小溪，冰涼的水絲一般地湧入指縫又伸懶腰似的從其中舒展開來，
被泉水滋潤一樣的舒服。
LONG);
	set("exits",  ([
		"northeast"  :  __DIR__"kongdi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "5lt");
	set("coor/x", -195);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}