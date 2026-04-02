//Room: /d/city/shuyuan3.c 
string look_table();

#define STORY_TOC "/doc/book/toc"
#define STORY_DIR "/doc/book/"
inherit ROOM;

void create()
{
	set("short", "射鵰院");
	set("long", @LONG
這是一間軒敞明淨的大屋子，正中一張大書桌 (table)，上面摞了
幾疊書。這裏收藏了武俠大師金庸先生的主要作品，所有驚心動魄、婉
約深情的故事，由大師的生花妙筆娓娓道來。許多成名後的大俠時常來
這裏走走、看看，回味自己漫長的江湖歲月中那些彌足珍貴的感受，以
自己坎坷的刀劍生涯印證大師的手筆，並寫下自己走上江湖之路。夜深
人靜時，如果您仍輾轉難眠，不妨翻翻 (fan)這些書。樓下是飛雪堂，
收藏俠客行早期玩家的作品。
LONG);
	set("item_desc", ([
	    "table" : (: look_table :),
	]));
	set("exits", ([
	    "down" : __DIR__"shuyuan2",
	]));
	set("objects", ([
	    __DIR__"player/aiwoaini" : 1,
	    __DIR__"player/autodami" : 1,
	    __DIR__"player/august" : 1,
	    __DIR__"player/batwing" : 1,
	    __DIR__"player/karice" : 1,
	    __DIR__"player/piaoxue" : 1,
	    __DIR__"player/qianqiu" : 1,
	    __DIR__"player/tiji" : 1,
	    __DIR__"player/welcome" : 1,
	    __DIR__"player/wpp" : 1,
	    __DIR__"player/wrong" : 1,
	    __DIR__"player/yzjiang" : 1,
	]));
	set("no_fight", 1);
	set("coor/x", 20);
	set("coor/y", 32);
	set("coor/z", 30);
	setup();
}

void init()
{
	add_action("do_fan", "fan");
}

string look_table()
{
	this_player()->start_more(read_file(STORY_TOC));
	return "\n";
}

int do_fan(string arg)
{
	object me=this_player();
	if (arg == "" || file_size(STORY_DIR + arg) <= 0)
		return notify_fail("我們沒有這本書。\n");

	log_file("LIBRARY", sprintf("%s read %s.\n", me->query("name"), arg));
	me->start_more(read_file(STORY_DIR + arg));
	return 1;
}
