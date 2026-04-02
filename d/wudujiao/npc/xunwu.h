// xunwu.h
int do_attack(string arg)
{
	object ob;
	string host_id;
	object me=this_player();
	object who=this_object();
	if(environment(me)->query("no_fight"))
		return notify_fail(who->query("name")+"全身扭動，畏縮不前！\n");
	if(environment(me)->query("no_ansuan"))
		return notify_fail(who->query("name")+"全身扭動，畏縮不前！\n");
	if(me->query("id")!=(who->query("host_id")))
		return notify_fail(who->query("name")+"連理都不理你！\n");
	if(!arg||!objectp(ob=present(arg,environment(me))))
		return notify_fail(who->query("name")+"傻傻地望着你，不明白你的意思。\n");
	if(ob->query("id")==me->query("id"))
		return notify_fail(who->query("name")+"急忙把頭一低，似乎不願意去幹。\n");
	if(ob->query("owner")&&ob->query("owner")!=me->query("id"))
		return notify_fail(who->query("name")+"全身扭動，畏縮不前！\n");
	if(!living(ob))
		return notify_fail(who->query("name")+"說："+ob->query("name")+"已經這樣啦你還要....？！\n");
	message_vision(who->query("name")+"吱吱怪叫一聲衝了出去。\n",me);
	fight_ob(ob);
	return 1;
}

int do_stop()
{
	object who=this_object();
	string host_id;
	object me=this_player();
	if(me->query("id")!=(who->query("host_id")))
		return notify_fail(who->query("name")+"連理都不理你！\n");
	who->set_leader(me);
	message_vision("$N對"+who->query("name")+"喝道：別打了，跟我來。\n",me);
//	if(!is_fighting())
//		return notify_fail(who->query("name")+"現在沒和人打鬥。\n");
	command("halt");
	who->delete_temp("kill_name");
	message_vision(who->query("name")+"乖乖的回到$N身邊。\n",me);
	return 1;
}

int do_sha(string arg)
{
	object who=this_object();
	int i ;
	object me,ob;
	object* obj;

	if(environment(me)->query("no_ansuan"))
		return notify_fail(who->query("name")+"全身扭動，畏縮不前！\n");
	me = this_player();
	if(me->query("id")!=(who->query("host_id")))
		return notify_fail(who->query("name")+"連理都不理你！\n");
	if(!arg||!objectp(ob=present(arg,environment(me))))
		return notify_fail("你要"+who->query("name")+"殺誰？\n");
	if(ob->query("id")==me->query("id"))
		return notify_fail( who->query("name")+"急忙把頭一低，似乎不願意去幹。\n");
	if(!environment(ob)->query("no_fight"))
	{
		message_vision(who->query("name")+"吱吱怪叫一聲衝了出去。\n",me);
		who->set_leader(ob);
		who->set_temp("kill_name",ob->query("id"));
		remove_call_out("kill_ob");
		call_out("kill_ob", 0, ob);
	}
	return 1;
}
int do_guard(string arg)
{
	object who=this_object();
	int i ;
	object me,ob;
	object* enemy;
	me = this_player();
	if(me->query("id")!=(who->query("host_id")))
		return notify_fail(who->query("name")+"連理都不理你！\n");
	if(!arg)
	ob = this_player();
	if(arg)
	{
		if(!userp(present(arg,environment(me))))
			return notify_fail("你要"+who->query("name")+"保護誰？\n");
	}
	if(arg) ob = present(arg,environment(me));
	if (ob->is_fighting())
	{
		return notify_fail("對方好像不願意接受你的好意！\n");
	}
	who->set_temp("guard_ob",ob->query("id"));
	message("vision",
		 name() + "發出輕微的吱叫聲，開始繞着"+ob->name()+"四處遊走！\n"NOR,environment(), this_object() );
	enemy = ob->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
		}
	}
	ob->remove_all_killer();
	who->set_leader(ob);
	return 1;
}
int do_hit(string arg)
{
	object ob = this_object();
	object me = this_player();
	object gurad_ob;

	if(environment(me)->query("no_fight"))
		return notify_fail(ob->query("name")+"畏縮不前！\n");
	if(environment(me)->query("no_ansuan"))
		return notify_fail(ob->query("name")+"畏縮不前！\n");
	if (!arg ) return 0;
	if (arg != ob->query_temp("guard_ob")) return 0;
	message_vision("$N一聲怪叫忽然擋在了"+me->name()+"的面前。\n", this_object());
	remove_call_out("kill_ob");
	call_out("kill_ob", 0, me);
	return 1;
}
