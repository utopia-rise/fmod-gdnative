extends "res://addons/gut/test.gd"

class TestEvent:
	extends "res://addons/gut/test.gd"
	
	var id: int
	
	func before_all():
		# load banks
		# warning-ignore:return_value_discarded
		Fmod.load_bank("./assets/Banks/Master Bank.strings.bank", Fmod.FMOD_STUDIO_LOAD_BANK_NORMAL)
		# warning-ignore:return_value_discarded
		Fmod.load_bank("./assets/Banks/Master Bank.bank", Fmod.FMOD_STUDIO_LOAD_BANK_NORMAL)
		# warning-ignore:return_value_discarded
		Fmod.load_bank("./assets/Banks/Music.bank", Fmod.FMOD_STUDIO_LOAD_BANK_NORMAL)
		# warning-ignore:return_value_discarded
		Fmod.load_bank("./assets/Banks/Vehicles.bank", Fmod.FMOD_STUDIO_LOAD_BANK_NORMAL)
		Fmod.set_listener_number(1)
		Fmod.add_listener(0, self)
		id = Fmod.create_event_instance("event:/Vehicles/Car Engine")
		Fmod.attach_instance_to_node(id, self)
		Fmod.set_event_parameter_by_name(id, "RPM", 600)
		Fmod.start_event(id)
	
	func after_all():
		Fmod.stop_event(id, Fmod.FMOD_STUDIO_STOP_IMMEDIATE)
		Fmod.release_event(id)
		Fmod.remove_listener(0)
		Fmod.unload_bank("./assets/Banks/Master Bank.strings.bank")
		Fmod.unload_bank("./assets/Banks/Master Bank.bank")
		Fmod.unload_bank("./assets/Banks/Music.bank")
		Fmod.unload_bank("./assets/Banks/Vehicles.bank")
	
	func test_assert_set_volume():
		var desired_value: float = 4.0
		Fmod.set_event_volume(id, desired_value)
		assert_eq(Fmod.get_event_volume(id), desired_value, "Event volume should be 4")
	
	func test_assert_set_pitch():
		var desired_value: float = 0.75
		Fmod.set_event_pitch(id, desired_value)
		assert_eq(Fmod.get_event_pitch(id), desired_value, "Event pitch should be 0.75")
	
	func test_assert_paused():
		Fmod.set_event_paused(id, true)
		assert_true(Fmod.get_event_paused(id), "Event should be paused")
	
	func test_assert_timeline_position():
		var desired_value: int = 10
		Fmod.set_event_timeline_position(id, desired_value)
		Fmod.set_event_paused(id, true)
		var t = Timer.new()
		t.set_wait_time(3)
		t.set_one_shot(true)
		self.add_child(t)
		t.start()
		yield(t, "timeout")
		assert_eq(Fmod.get_event_timeline_position(id), 10, "Event timeline should be at " + str(desired_value))
	
	func test_assert_event_reverb():
		var desired_value: float = 1.5
		Fmod.set_event_reverb_level(id, 0, desired_value)
		assert_eq(Fmod.get_event_reverb_level(id, 0), desired_value, "Event reverb level should be " + str(desired_value))
	
	func test_assert_event_parameter_by_name():
		var desired_value: int = 600
		assert_eq(Fmod.get_event_parameter_by_name(id, "RPM"), desired_value, "Event parameter RPM should be 600")