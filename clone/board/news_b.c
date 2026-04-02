// /clone/board/news_b.c

inherit BULLETIN_BOARD;

void create()
{
	seteuid(getuid());
	set_name("更新公告版", ({ "board" }) );
	set("location", "/u/lijia/workroom");
	set("board_id", "news_b");
	set("long", "這是一個巫師提供更新消息時用的留言板。\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

