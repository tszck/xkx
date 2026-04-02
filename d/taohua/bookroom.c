// Room: /d/taohua/bookroom.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
 int b1,b2,b3;
	string temp;
	object y1,y2,y3;
	set("short", "書房");
	set("long", @LONG
這裏是黃藥師讀書的地方。窗明幾淨，一塵不染。一張古意盎然的
書案放在房間正中，案上擺着幾本翻開了的線裝書籍。靠牆的地方還有
一個書架，架上滿滿的全是各種封裝的書。其中不少書看上去古意盎然，
顯然年代已久。
LONG
	);
	set("exits", ([
		"west" : __DIR__"zoulang4",
	]));
	set("objects", ([
//		"/clone/book/yijing"+random(4) : 1,
//		"/clone/book/yijing"+random(4) : 1,
//		"/clone/book/bagua"+random(2)  : 1,
	]));
	set("coor/x", 9030);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	b1 = random(4);
	temp = "/clone/book/yijing" + b1;
	y1 = new(temp);
	if (y1->violate_unique())	destruct(y1);
	else 	y1 ->move(this_object());
	b2 = random(4);
	temp = "/clone/book/yijing" + b2;
	y2 = new(temp);
	if (y2->violate_unique())	destruct(y2);
	else 	y2 ->move(this_object());
	b3 = random(2);
	temp = "/clone/book/bagua" + b3;
	y3 = new (temp);
	if (y3->violate_unique())	destruct(y3);
	else 	y3 ->move(this_object());
	replace_program(ROOM);
}