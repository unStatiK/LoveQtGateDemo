require "qtgate"

function love.load() 
	rt = qtgate.init()	
    qt_version = qtgate.get_qt_version(rt)
	meta_info = qtgate.get_meta_info(rt)
end

function love.draw() 	
	love.graphics.setColor(255, 255, 255)
	love.graphics.print("powered by "..qt_version, 50, 100 )
	love.graphics.print("From Sqlite db meta info:", 50, 150 )

	love.graphics.print("version -", 50, 170 )
	love.graphics.setColor(255, 255, 35)
	love.graphics.print(meta_info.db_v, 110, 170 )
	love.graphics.setColor(255, 255, 255)

	love.graphics.print("description -", 50, 190 )
	love.graphics.setColor(255, 255, 35)
	love.graphics.print(meta_info.desc, 132, 190 )
	love.graphics.setColor(255, 255, 255)
end