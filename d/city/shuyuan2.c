//Room: /d/city/shuyuan2.c

string look_shelf();

#define STORY_TOC "/doc/legend/toc"
#define STORY_DIR "/doc/legend/"
inherit ROOM;

void create()
{
	set("short", "飛雪堂");
	set("long", @LONG
這是俠客行玩家們閒暇時喜歡逗留的地方。這裏窗明幾淨，一塵不
染。壁上的書架(shelf) 堆滿俠客行的先賢們的文選，記錄了俠客行的
風風雨雨和無數或悽婉深情或粗豪奔放的傳説，雖然那些日子已經很遙
遠，卻難以磨滅。你可以閲讀(read)到這些古老的故事。樓上是射鵰院，
收藏有金庸大師的主要作品。
LONG);
	set("item_desc", ([
		"shelf" : (: look_shelf :),
	]));
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);

	set("exits", ([
		"down" : __DIR__"shuyuan1",
		"up"   : __DIR__"shuyuan3",
	]));
	set("objects", ([
		__DIR__"obj/wizboard" : 1,
	]));
	set("coor/x", 20);
	set("coor/y", 32);
	set("coor/z", 20);
	setup();
	"/clone/board/shuyuan_b"->foo();
}

void init()
{
	add_action("do_read", "read");
}

string look_shelf()
{
	this_player()->start_more(read_file(STORY_TOC));
	return "\n";
}

int do_read(string arg)
{
	object me=this_player();
	if (arg == "" || file_size(STORY_DIR + arg) <= 0)
		return notify_fail("我們沒有這本書。\n");

	log_file("LIBRARY", sprintf("%s read %s.\n", me->query("name"), arg));
	me->start_more(read_file(STORY_DIR + arg));
	return 1;
}
