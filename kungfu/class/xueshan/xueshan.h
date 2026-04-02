// xueshan.h

string ask_for_join()
{
	object me = this_player();

	if( (string)me->query("class")=="lama" )
		return "阿彌陀佛！你我同是出家人，何故跟貧僧開這等玩笑？\n";

	if( (string)me->query("gender") != "男性" )
		return "施主若真心向佛，真是可喜可賀，可惜本寺只收男徒。\n";

	me->set_temp("pending/join_bonze", 1);
	return "阿彌陀佛！善哉！善哉！施主若真心皈依我佛，請跪下(kneel)受戒。\n";
}

int do_kneel()
{
	object me = this_player();

	if( !me->query_temp("pending/join_bonze") ) return 0;
	message_vision("$N雙手合十，恭恭敬敬地跪了下來。\n\n$n伸出手掌，在$N頭頂輕輕地摩挲了幾下，將$N的頭髮盡數剃去。\n\n", me, this_object() );
	command("smile");
	me->set("class", "lama");
	return 1;
}

