#ifndef VISUALIZER_HPP
#define VISUALIZER_HPP

#include <iostream>
#include <iomanip>
#include <cmath>
#include "Point.hpp"
#include "Fixed.hpp"

class Visualizer {
private:
    static const int WIDTH = 60;  // Increased for better resolution
    static const int HEIGHT = 30; // Increased for better resolution
    char grid[HEIGHT][WIDTH];
    float minX, maxX, minY, maxY;
    
    void initGrid() {
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                grid[y][x] = ' ';
            }
        }
        // Draw axes
        int centerX = WIDTH / 2;
        int centerY = HEIGHT / 2;
        for (int y = 0; y < HEIGHT; y++) grid[y][centerX] = '|';
        for (int x = 0; x < WIDTH; x++) grid[centerY][x] = '-';
    }

    void calculateBounds(const Point& a, const Point& b, const Point& c, const Point& p) {
        minX = std::min(std::min(std::min(a.getX().toFloat(), b.getX().toFloat()),
                                c.getX().toFloat()), p.getX().toFloat());
        maxX = std::max(std::max(std::max(a.getX().toFloat(), b.getX().toFloat()),
                                c.getX().toFloat()), p.getX().toFloat());
        minY = std::min(std::min(std::min(a.getY().toFloat(), b.getY().toFloat()),
                                c.getY().toFloat()), p.getY().toFloat());
        maxY = std::max(std::max(std::max(a.getY().toFloat(), b.getY().toFloat()),
                                c.getY().toFloat()), p.getY().toFloat());

        // Ensure minimum range to prevent division by zero
        if (maxX - minX < 0.1f) {
            float mid = (maxX + minX) / 2;
            minX = mid - 0.05f;
            maxX = mid + 0.05f;
        }
        if (maxY - minY < 0.1f) {
            float mid = (maxY + minY) / 2;
            minY = mid - 0.05f;
            maxY = mid + 0.05f;
        }

        // Add padding (20% of range)
        float xPadding = (maxX - minX) * 0.2f;
        float yPadding = (maxY - minY) * 0.2f;
        minX -= xPadding;
        maxX += xPadding;
        minY -= yPadding;
        maxY += yPadding;
    }

    int mapX(float x) const {
        return static_cast<int>(((x - minX) / (maxX - minX)) * (WIDTH - 1));
    }

    int mapY(float y) const {
        return static_cast<int>((HEIGHT - 1) - ((y - minY) / (maxY - minY)) * (HEIGHT - 1));
    }

    void plotPoint(float x, float y, char symbol) {
        int gridX = mapX(x);
        int gridY = mapY(y);
        
        if (gridX >= 0 && gridX < WIDTH && gridY >= 0 && gridY < HEIGHT) {
            grid[gridY][gridX] = symbol;
        }
    }

    void drawLine(float x1, float y1, float x2, float y2) {
        int gridX1 = mapX(x1);
        int gridY1 = mapY(y1);
        int gridX2 = mapX(x2);
        int gridY2 = mapY(y2);

        int dx = std::abs(gridX2 - gridX1);
        int dy = std::abs(gridY2 - gridY1);
        int sx = gridX1 < gridX2 ? 1 : -1;
        int sy = gridY1 < gridY2 ? 1 : -1;
        int err = dx - dy;

        while (true) {
            if (gridX1 >= 0 && gridX1 < WIDTH && gridY1 >= 0 && gridY1 < HEIGHT) {
                if (grid[gridY1][gridX1] == ' ' || grid[gridY1][gridX1] == '|' || grid[gridY1][gridX1] == '-') {
                    grid[gridY1][gridX1] = '*';
                }
            }

            if (gridX1 == gridX2 && gridY1 == gridY2) break;

            int e2 = 2 * err;
            if (e2 > -dy) { err -= dy; gridX1 += sx; }
            if (e2 < dx) { err += dx; gridY1 += sy; }
        }
    }

public:
    void drawTriangle(const Point& a, const Point& b, const Point& c, const Point& testPoint) {
        initGrid();
        calculateBounds(a, b, c, testPoint);

        // Draw the triangle edges first
        drawLine(a.getX().toFloat(), a.getY().toFloat(),
                b.getX().toFloat(), b.getY().toFloat());
        drawLine(b.getX().toFloat(), b.getY().toFloat(),
                c.getX().toFloat(), c.getY().toFloat());
        drawLine(c.getX().toFloat(), c.getY().toFloat(),
                a.getX().toFloat(), a.getY().toFloat());

        // Then plot the points on top
        plotPoint(a.getX().toFloat(), a.getY().toFloat(), 'A');
        plotPoint(b.getX().toFloat(), b.getY().toFloat(), 'B');
        plotPoint(c.getX().toFloat(), c.getY().toFloat(), 'C');
        plotPoint(testPoint.getX().toFloat(), testPoint.getY().toFloat(), 'P');

        std::cout << "\nCartesian plane with triangle and test point:\n\n";

        // Print Y-axis coordinates and grid
        for (int y = 0; y < HEIGHT; y++) {
            if (y % 2 == 0) {
                float yCoord = maxY - (y * (maxY - minY) / (HEIGHT - 1));
                std::cout << std::fixed << std::setprecision(2) << std::setw(6) << yCoord << " ";
            } else {
                std::cout << "       ";
            }

            for (int x = 0; x < WIDTH; x++) {
                std::cout << grid[y][x];
            }
            std::cout << "\n";
        }

        // Print X-axis coordinates
        std::cout << "       ";
        for (int x = 0; x < WIDTH; x += WIDTH/6) {
            float xCoord = minX + (x * (maxX - minX) / (WIDTH - 1));
            std::cout << std::fixed << std::setprecision(2) << std::setw(10) << xCoord;
        }

        std::cout << "\n\nLegend:\n";
        std::cout << "A, B, C: Triangle vertices\n";
        std::cout << "P: Test point\n";
        std::cout << "*: Triangle edges\n";
    }
};

#endif
