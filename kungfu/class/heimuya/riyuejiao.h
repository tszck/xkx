// MingJiao.h for all npc of mingjiao

void greeting(object me, object ob)
{
	if ( environment(ob) != environment(me) ) return;
	if ( ob->query("party/party_name") == HIB "日月神教" NOR )
	{
//		if ( ob->query("party/level") < me->query("level"))
		message_vision("$N對$n躬身行禮，説道："+me->query("title")+me->query("name")+"，參見"+ob->query("party")["rank"]+ob->query("name")+"！教主千秋萬載，一統江湖！\n", me, ob );
	}
	return;
}
