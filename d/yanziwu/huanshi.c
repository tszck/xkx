//ROOM: /d/yanziwu/huanshi.c

inherit ROOM;

void create()
{
	set("short", "還施水閣");
	set("long",@LONG
這裏就是武林中人人心儀的慕容家藏書之所。天下習武之人，凡聞
“以彼之道，還施彼身”之名者，莫不希望來此，發掘慕容世家絕技的
祕密。閣中滿是書架，架上擺着許多頗為古舊的書籍，架上均貼有標籤
(sign)。這就是慕容世家歷經數代才收集積累而成的武學寶庫。
LONG );
	set("exits", ([
		"north": __DIR__"jiashan",
	]));
	set("objects", ([
		__DIR__"book/leg_book": random(2),
		__DIR__"book/cuff_book": random(2),
		__DIR__"book/claw_book": random(2),
		__DIR__"book/hand_book": random(2),
		__DIR__"book/dodge_book": random(2),
		__DIR__"book/finger_book": random(2),
		__DIR__"book/strike_book": random(2),
		__DIR__"book/unarmed_book": random(2),
	]));
	set("item_desc",([
		"sign" : "簽上標着少林、武當、青城、大理等門派的名稱。\n"
	]));
	set("no_clean_up", 0);
	set("coor/x", 840);
	set("coor/y", -1541);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
